#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>

#include "FlightComputer/PodInternalNetwork.h"
#include "FlightComputer/nodeSim.h"

int main(int argc, char** argv)
{
  PodValues* pvPodValues;
  int iServerSocket = createNodeServerSocket();
  clientSocketConfig* iClientSocket = initializeClientSocket();
  std::thread tServer(nodeServerThread, iServerSocket, pvPodValues);
  std::thread tSim(runNodeSimulator, iClientSocket);
  tServer.join();
  tSim.join();
  return 0;
}
