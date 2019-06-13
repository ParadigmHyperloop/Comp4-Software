#include "States.h"

PodState::PodState() = default;

PodState::PodState(TelemetryManager* pod){
    this->pod = pod;
    this->_enterStateTime = std::chrono::steady_clock::now();
}

unsigned int PodState::timeInStateMilis() {
    std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(current - this->_enterStateTime).count();
}

int32_t PodState::checkSensorFlags(){
    std::vector<int32_t> flags = this->pod->telemetry->sensorFlags;
    for(std::size_t i=0; i<flags.size(); ++i){
        if(flags[i] == 0){
            return i;
        }
    }
    return FLAGS_GOOD;
}

int32_t PodState::checkCommunicationFlags(){
    std::vector<int32_t> flags = this->pod->telemetry->connectionFlags;
    for(std::size_t i=0; i<flags.size(); ++i){
        if(flags[i] == 0){
            return i;
        }
    }
    return FLAGS_GOOD;
}

int32_t PodState::checkNodeStates(){
    if(this->_brakeNodeState != this->pod->telemetry->brakeNodeState){
        return BRAKE_NODE_INDEX;
    }
    if(this->_lvdcNodeState != this->pod->telemetry->lvdcNodeState){
        return LVDC_NODE_INDEX;
    }
    return FLAGS_GOOD;
}

void PodState::commonChecks() {
    int32_t status;

    status = this->checkSensorFlags();
    if( status != FLAGS_GOOD ){
        std::string error = "Failed on sensor : " + std::to_string(status) + " returning to standby.";
        throw std::runtime_error(error);
    }
    status = this->checkCommunicationFlags();
    if(status != FLAGS_GOOD){
        std::string error = "Failed on communication flag : " + std::to_string(status) + " returning to standby.";
        throw std::runtime_error(error);
    }
    status = this->checkNodeStates();
    if(status != FLAGS_GOOD && this->timeInStateMilis() > 500){
        std::string error = "Failed on node state agreement : " + std::to_string(status) + " returning to standby.";
        throw std::runtime_error(error);
    }
}

void PodState::setupTransition(PodStates nextState, const std::string& reason){
    this->_transitioning = true;
    this->_transitionReason = reason;
    this->_nextStateIdentifier = nextState;
}

bool PodState::testTransitions(){
    return true;
}

PodStates PodState::getStateValue(){
    return this->_stateIdentifier;
}

PodStates PodState::getNewState(){
    return this->_nextStateIdentifier;
}

bool PodState::isTransitioning(){
    return this->_transitioning;
}

LvdcNodeStates PodState::getLvdcNodeState(){
    return _lvdcNodeState;
}

BrakeNodeStates PodState::getBrakeNodeState(){
    return _brakeNodeState;
}

const std::string PodState::getTransitionReason(){
    return _transitionReason;
}

std::unique_ptr<PodState> PodState::createState(PodStates newState, TelemetryManager* telemetry) {
    switch (newState) {
        case psBooting:
            return std::unique_ptr<PodState>(new Booting(telemetry));
        case psStandby:
            return std::unique_ptr<PodState>(new Standby(telemetry));
        case psArming:
            return std::unique_ptr<PodState>(new Arming(telemetry));
        case psArmed:
            return std::unique_ptr<PodState>(new Armed(telemetry));
        case psPreFlight:
            return std::unique_ptr<PodState>(new PreFlight(telemetry));
        case psAcceleration:
            return std::unique_ptr<PodState>(new Acceleration(telemetry));
        case psBraking:
            return std::unique_ptr<PodState>(new Braking(telemetry));
        default:
            return std::unique_ptr<PodState>(new Braking(telemetry));
    }
}

/*
 *  ******************** BOOTING ***********************8
 */

Booting::Booting(TelemetryManager* pod): PodState(pod) {
    _stateIdentifier = psBooting;
    _brakeNodeState = bnsBooting;
    _lvdcNodeState = lvdcBooting;
}

bool Booting::testTransitions(){
    this->setupTransition(psStandby, "Booting Complete");
    return true;
}

/*
 *  ******************** STANDBY ***********************8
 */
//TelemetryManager*

Standby::Standby(TelemetryManager * pod): PodState(pod) {
    _stateIdentifier = psStandby;
    _brakeNodeState = bnsStandby;
    _lvdcNodeState = lvdcStandby;
}


bool Standby::testTransitions() {
    int32_t status;

    try {
        this->commonChecks();
    }
    catch (const std::runtime_error &e ){
        //failing on e.what()
    }

    if(this->pod->telemetry->controlsInterfaceState == ciArm){
        this->setupTransition(psArming, (std::string)"Arm Command Received : All Nominal");
        return true;
    }
    return false;
}

/*
 *  ******************** ARMING ***********************8
 */

Arming::Arming(TelemetryManager * pod ): PodState(pod) {
    _stateIdentifier = psArming;
    _brakeNodeState = bnsStandby;
    _lvdcNodeState = lvdcFlight;
}

bool Arming::testTransitions() {
    try {
        this->commonChecks();
    }
    catch (const std::runtime_error &error ){
        this->setupTransition(psStandby, error.what());
        return true;
    }
    //todo validate that we are receiving telemetry from the inverter
    if(true){
        this->setupTransition(psArmed, (std::string)"All values nominal");
        return true;
    }
    return false;
}

/*
 *  ******************** ARMED ***********************8
 */

Armed::Armed(TelemetryManager * pod) : PodState(pod) {
    _stateIdentifier = psArming;
    _brakeNodeState = bnsStandby;
    _lvdcNodeState = lvdcFlight;
}

bool Armed::testTransitions() {
    try {
        this->commonChecks();
    }
    catch (const std::runtime_error &error ){
        this->setupTransition(psStandby, error.what());
        return true;
    }

    // todo inverter comms
    if(this->pod->telemetry->controlsInterfaceState == ciFlight){
        this->pod->telemetry->controlsInterfaceState = ciNone; // Use up command
        this->setupTransition(psPreFlight, (std::string)"Flight Command Received : All Nominal");
        return true;
    }
    return false;
}


/*
 *  ******************** PREFLIGHT ***********************8
 */
PreFlight::PreFlight(TelemetryManager* pod) : PodState(pod) {
    _stateIdentifier = psPreFlight;
    _brakeNodeState = bnsFlight;
    _lvdcNodeState = lvdcFlight;
}

bool PreFlight::testTransitions() {
    try {
        this->commonChecks();
    }
    catch (const std::runtime_error &error ){
        this->setupTransition(psStandby, error.what());
    }

    // todo inverter comms
    this->setupTransition(psAcceleration, (std::string)"Node in Flight State : All Nominal");
    return true;

    return false;
}



/*
 *  ******************** ACCELERATION ***********************8
 */


Acceleration::Acceleration(TelemetryManager * pod) : PodState(pod) {
    _stateIdentifier = psAcceleration;
    _brakeNodeState = bnsFlight;
    _lvdcNodeState = lvdcFlight;
}

bool Acceleration::testTransitions() {
    // todo critical vs non critical changes
    try {
        this->commonChecks();
    }
    catch (const std::runtime_error &error ){
        this->setupTransition(psBraking, error.what());
        return true;
    }
    // Navigation checks
    // todo inverter comms and bms
    if(this->timeInStateMilis() > this->pod->telemetry->maxFlightTime ){
        this->setupTransition(psBraking, (std::string)" Flight Timout Reached");
        return true;
    }
    return false;
}

/*
 *  ******************** BRAKING ***********************8
 */

Braking::Braking(TelemetryManager* pod) : PodState(pod) {
    _stateIdentifier = psBraking;
    _brakeNodeState = bnsBraking;
    _lvdcNodeState = lvdcFlight;
}

bool Braking::testTransitions() {
    return false;
}