#include "FlightComputer/PodInternalNetwork.h"
#include "FlightComputer/MemoryAccess.h"
#define UDPPORT 5008

using namespace fc;

void parseBreakNodePacket(fc::brakeNodeData pPayload, MemoryAccess Pod){
	//Grab State
	switch (pPayload.state()){
		case brakeNodeData::bnsBooting:
		{
			Pod.setBrakeNodeState(bnsBooting);
			break;
		}
		case brakeNodeData::bnsStandby:
		{
			Pod.setBrakeNodeState(bnsStandby);
			break;
		}
		case brakeNodeData::bnsArming:
		{
			Pod.setBrakeNodeState(bnsArming);
			break;
		}
		case brakeNodeData::bnsArmed:
		{
			Pod.setBrakeNodeState(bnsArmed);
			break;
		}
		case brakeNodeData::bnsFlight:
		{
			Pod.setBrakeNodeState(bnsFlight);
			break;
		}
		case brakeNodeData::bnsBraking:
		{
			Pod.setBrakeNodeState(bnsBraking);
			break;
		}
		case brakeNodeData::bnsVenting:
		{
			Pod.setBrakeNodeState(bnsVenting);
			break;
		}
		case brakeNodeData::bnsRetrieval:
		{
			Pod.setBrakeNodeState(bnsRetrieval);
			break;
		}
		case brakeNodeData::bnsError:
		{
			Pod.setBrakeNodeState(bnsError);
			break;
		}
		default:
		{
			Pod.setBrakeNodeState(bnsError);
		}
		/*Offload Data
		Pod->bSolenoid1 = pPayload.sol1();
		Pod->bSolenoid2 = pPayload.sol2();
		Pod->bSolenoid3 = pPayload.sol3();
		Pod->bSolenoid4 = pPayload.sol4();
		Pod->bSolenoid5 = pPayload.sol5();
		Pod->bSolenoid6 = pPayload.sol6();
		Pod->iLowPressure1 = pPayload.lp1();
		Pod->iLowPressure2 = pPayload.lp2();
		Pod->iLowPressure3 = pPayload.lp3();
		Pod->iLowPressure4 = pPayload.lp4();
		Pod->iHighPressure = pPayload.hp();
		Pod->iPressureVesselTemperature = pPayload.temp();
		*/
	}
}

/**
 * createNodeServerSocket
 *
 * returns: The socket discriptor number that is associated with the created socket
 * params: None
 *
 * Create the UDP socket that Pod Internal Work Node telemetry will be recieved on.
 */
int createNodeServerSocket() {
  int iPort = UDPPORT;
  int iSocket;
  struct sockaddr_in SocketAddrStruct;
  iSocket = socket(AF_INET, SOCK_DGRAM, 0);
 // memset(&SocketAddrStruct, '\0', sizeof(SocketAddrStruct));  //Replacement, I read online this isnt even needed??
  SocketAddrStruct.sin_family = AF_INET;
  SocketAddrStruct.sin_port = htons(iPort);
  SocketAddrStruct.sin_addr.s_addr = inet_addr("127.0.0.1");
  bind(iSocket, (struct sockaddr*)&SocketAddrStruct, sizeof(SocketAddrStruct));
  return iSocket;
}

/**
 *Wait on socket, parse the recieved message into a protobuf and hand it off.
 */
int nodeServerThread(MemoryAccess* Pod)
{
	int iSocket = createNodeServerSocket();
	char cBuffer[100] = {0};
	while (1)
	{
		bzero(&cBuffer, sizeof cBuffer);
		printf("Waiting to recieve on socket: %i \n", iSocket);
		int iRecievedPacketSize = recvfrom(iSocket, cBuffer, 300, 0, nullptr, nullptr);
		fc::brakeNodeData pNodeUpdate;
		bool bProtoPacketParsed = pNodeUpdate.ParseFromArray(&cBuffer, iRecievedPacketSize);
		if(bProtoPacketParsed)
		{
			printf("Contents are: \n%s \n", pNodeUpdate.DebugString().c_str());
			parseBreakNodePacket( pNodeUpdate,*Pod);
		}
		else
		{
			printf("Error Parsing Protobuf packet");
		}
	}
	close(iSocket);
	return 0;
}

