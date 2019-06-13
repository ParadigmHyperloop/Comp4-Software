#ifndef FLIGHTCOMPUTER_STATES_H
#define FLIGHTCOMPUTER_STATES_H

#include "TelemetryManager.h"

#define FLAGS_GOOD -1
#define BRAKE_NODE_INDEX 1
#define LVDC_NODE_INDEX 2

class TelemetryManager;

class PodState{

public:
    PodState();

    PodState(TelemetryManager*);

    PodStates getStateValue();

    virtual bool testTransitions();

    PodStates getNewState();

    bool isTransitioning();

    BrakeNodeStates getBrakeNodeState();

    LvdcNodeStates getLvdcNodeState();

    const std::string getTransitionReason();

    unsigned int timeInStateMilis();

    static std::unique_ptr<PodState> createState(PodStates, TelemetryManager* );

    void setupTransition(PodStates, const std::string&);

    int32_t checkSensorFlags();

    int32_t checkCommunicationFlags();

    int32_t checkNodeStates();

    void commonChecks();


protected:
    std::chrono::steady_clock::time_point _enterStateTime;
    bool _transitioning = false;
    std::string _transitionReason = "";
    PodStates _stateIdentifier = psBooting;
    PodStates _nextStateIdentifier = psBooting;
    BrakeNodeStates _brakeNodeState = bnsBooting;
    LvdcNodeStates  _lvdcNodeState = lvdcBooting;
    TelemetryManager* pod;
};

class Booting: public PodState {
public:
    Booting(TelemetryManager*);
    bool testTransitions() override;
};

class Standby: public PodState {
public:
    Standby(TelemetryManager*);
    bool testTransitions() override;
};

class Arming : public PodState {
public:
    Arming(TelemetryManager*);

    bool testTransitions() override;
};

class Armed : public PodState {
public:
    Armed(TelemetryManager*);
    bool testTransitions() override;
};

class PreFlight : public PodState {
public:
    PreFlight(TelemetryManager*);
    bool testTransitions() override;
};

class Acceleration : public PodState {
public:
    Acceleration(TelemetryManager*);
    bool testTransitions() override;
};

class Braking : public PodState {
public:
    Braking(TelemetryManager*);
    bool testTransitions() override;
};

#endif //FLIGHTCOMPUTER_STATES_H
