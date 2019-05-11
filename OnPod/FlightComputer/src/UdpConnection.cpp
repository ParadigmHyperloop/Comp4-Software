#include "FlightComputer/UdpConnection.h"


UdpConnection::UdpConnection(Pod pod){
    this->pod = pod;
    struct sockaddr_in socketAddress = {0};
    this->_destSockAddr = socketAddress;
};

void UdpConnection::setRecvBufferSize(int32_t bufferSize) {
    //todo log failure
    int32_t s = setsockopt(this->_inboundSocket, SOL_SOCKET, SO_RCVBUF, &bufferSize, sizeof(bufferSize));
}


void UdpConnection::configureClient(const std::string &destIp, int32_t destPortNum, int32_t outboundSocket) {
    struct sockaddr_in sAddr = {0};
    this->_outboundSocket = outboundSocket;
    this->_destSockAddr = sAddr;
    this->_destSockAddr = createGenericNodeAddr();
    this->_destSockAddr.sin_port = htons(destPortNum);
    this->_destSockAddr.sin_addr.s_addr = inet_addr(destIp.c_str());
}


void UdpConnection::configureServer(int32_t serverPort, int32_t connectionTimeoutMilis) {
    this->_pulse = Heartbeat(connectionTimeoutMilis);
    this->_serverPort = serverPort;
    try {
        this->_createServerSocket();
    }
    catch (std::runtime_error &e) {
        throw e;
    }
}


void UdpConnection::getUpdate() {
    if (this->_inboundSocket == -1) {
        std::string error = "getUpdate() : Server socket invalid";
        throw std::runtime_error(error);
    }
    char buffer[200] = {0};
    bzero(&buffer, sizeof buffer);
    ssize_t receivedPacketSize = recvfrom(this->_inboundSocket, buffer, 200, 0, nullptr, nullptr);
    if (receivedPacketSize != -1) {
        LOG(INFO) << receivedPacketSize << " Bytes received on " << this->_connectionName << buffer;
        try {
            this->parseUpdate(buffer, (int32_t) receivedPacketSize);
        }
        catch (const std::invalid_argument &e) {
            std::string error = "getUpdate() : " + std::string(e.what());
            throw std::runtime_error(error);
        }
        this->_pulse.feed();
        this->setConnectionStatus(true);
    } else {
        if (this->_pulse.expired()) {
            this->setConnectionStatus(false);
        }
    }
}


void UdpConnection::giveUpdate() {
    google::protobuf::Message *protoPacket;
    ssize_t payloadSize;
    protoPacket = this->getProtoUpdateMessage();
    payloadSize = protoPacket->ByteSizeLong();
    unsigned char payload[payloadSize];

    if (!protoPacket->SerializeToArray(payload, static_cast<int>(payloadSize))) {
        std::string error = std::string("Error Creating Proto packet on  ") + this->_connectionName;
        delete protoPacket;
        throw std::runtime_error(error);
    }
    ssize_t sent = sendto(this->_outboundSocket, payload, payloadSize, 0,
                          (struct sockaddr *) &this->_destSockAddr, sizeof(this->_destSockAddr));
    if (sent == -1) {
        std::string strError = std::string("Error Sending ") + this->_connectionName + std::strerror(errno);
        delete protoPacket;
        throw std::runtime_error(strError);
    }
    delete protoPacket;
}

void UdpConnection::closeConnection() {
    close(this->_inboundSocket);
    close(this->_outboundSocket);
}


google::protobuf::Message* UdpConnection::getProtoUpdateMessage() {
    auto protoMessage = new defaultFcToNode();
    protoMessage->set_podstate(psArmed);
    return protoMessage;
};

bool UdpConnection::_createServerSocket() {
    int32_t serverSocket;
    struct sockaddr_in SocketAddr = {0};

    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket < 0) {
        std::string error = std::string(" Creating Server socket: ") + std::strerror(errno);
        throw std::runtime_error(error);
    }

    int flags = fcntl(serverSocket, F_GETFL);
    flags |= O_NONBLOCK;
    fcntl(serverSocket, F_SETFL, flags);

    SocketAddr.sin_family = AF_INET;
    SocketAddr.sin_port = htons(this->_serverPort);
    SocketAddr.sin_addr.s_addr = INADDR_ANY;
    int32_t status = bind(serverSocket, (struct sockaddr *) &SocketAddr, sizeof(SocketAddr));
    if (status < 0) {
        std::string sError = std::string("Binding Server Socket: ") + std::strerror(errno);
        throw std::runtime_error(sError);
    }
    this->_inboundSocket = serverSocket;
    return true;
}


PdsConnection::PdsConnection(Pod pod) : UdpConnection(pod) {
    this->_connectionName = "Controls Interface Data : ";
};

//TODO can we do this without putting the proto on the heap?
google::protobuf::Message* PdsConnection::getProtoUpdateMessage(){
    auto protoMessage = new telemetry();
    protoMessage->set_podstate(pod.sPodValues->ePodState);
    protoMessage->set_ilowpressure1(pod.sPodValues->iLowPressure1);
    protoMessage->set_ihighpressure(pod.sPodValues->iHighPressure);
    protoMessage->set_bsolenoid1(pod.sPodValues->bSolenoid1);
    protoMessage->set_bsolenoid2(pod.sPodValues->bSolenoid2);
    protoMessage->set_pressurevesseltemperature(pod.sPodValues->iPressureVesselTemperature);
    protoMessage->set_railtemperature(pod.sPodValues->iRailTemperature);
    protoMessage->set_ihvbatterypackvoltage(pod.sPodValues->fHvBatteryPackVoltage);
    protoMessage->set_ihvbatterypackcurrent(pod.sPodValues->iHvBatteryPackCurrent);
    protoMessage->set_ihvbatterypackmaxcellvoltage(pod.sPodValues->iHvBatteryPackMaxCellVoltage);
    protoMessage->set_ihvbatterypackminimumcellvoltage(pod.sPodValues->iHvBatteryPackMinimumCellVoltage);
    return protoMessage;
}




BrakeNodeConnection::BrakeNodeConnection(Pod pod) : UdpConnection(pod) {
    this->_connectionName = "Brake Node : ";
};

void BrakeNodeConnection::setConnectionStatus(bool status){
    this->pod.sPodValues->cConnectionsArray[0] = status;
}

google::protobuf::Message* BrakeNodeConnection::getProtoUpdateMessage() {
    auto protoMessage = new FcToBrakeNode();
    protoMessage->set_podstate(psArmed);
    protoMessage->set_manualnodestate(bnsArmed);
    return protoMessage;
}

bool BrakeNodeConnection::parseUpdate(char buffer[], int32_t messageSize){
    DtsNodeToFc protoMessage = DtsNodeToFc();
    if (!protoMessage.ParseFromArray(buffer, messageSize)) {
        std::string strError = "Failed to parse Update from Brake Node";
        throw std::invalid_argument(strError);
    }
    this->pod.sPodValues->bSolenoid1 = protoMessage.brakesolenoidstate();
    this->pod.sPodValues->bSolenoid2 = protoMessage.ventsolenoidstate();
    this->pod.sPodValues->iRailTemperature = protoMessage.rotortemperature();
    this->pod.sPodValues->iPressureVesselTemperature = protoMessage.pneumatictemperature();
    this->pod.sPodValues->iHighPressure = protoMessage.tankpressure();
    this->pod.sPodValues->iLowPressure1 = protoMessage.brakepressure();
    return true;
}



