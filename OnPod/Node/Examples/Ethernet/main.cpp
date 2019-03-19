#include <Arduino.h>
#include <Ethernet.h>

enum eNodeType {
	BRAKE = 1,
	LVDC = 2,
	REAR = 3
};

eNodeType iNodeType = REAR;
uint8_t mac[] {iNodeType, 0xFF, 0xFF, 0xFF, 0xFF};
IPAddress ip(192, 168, 0, 1);
uint16_t port = 777;

char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
char ReplyBuffer[] = "acknowledged";

IPAddress subnet(255, 255, 0, 0);

EthernetUDP Udp;

void setup() {
    Serial.begin(9600);
    while (!Serial) {}
    Ethernet.init(PIN_SPI_SS);
    Ethernet.begin(mac, ip);

    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
        Serial.println("Wiznet was not found or is not responding");
    }
    else if (Ethernet.linkStatus() == LinkOFF) {
        Serial.println("Ethernet cable is not connected.");
    }
    else
        Serial.println("Wiznet ready, cable connected");

    Udp.begin(port);
}

void loop() {
    // if there's data available, read a packet
    int packetSize = Udp.parsePacket();
    if (packetSize) {
        Serial.print("Received packet of size ");
        Serial.println(packetSize);
        Serial.print("From ");
        IPAddress remote = Udp.remoteIP();
        for (int i=0; i < 4; i++) {
            Serial.print(remote[i], DEC);
            if (i < 3) {
                Serial.print(".");
            }
        }
        Serial.print(", port ");
        Serial.println(Udp.remotePort());

        // read the packet into packetBufffer
        Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
        Serial.println("Contents:");
        Serial.println(packetBuffer);

        // send a reply to the IP address and port that sent us the packet we received
        Udp.beginPacket(Udp.remoteIP(), 7777, Udp.remoteIP(), subnet);
        Udp.write(ReplyBuffer);
        Udp.endPacket();
    }
    delay(10);
}
