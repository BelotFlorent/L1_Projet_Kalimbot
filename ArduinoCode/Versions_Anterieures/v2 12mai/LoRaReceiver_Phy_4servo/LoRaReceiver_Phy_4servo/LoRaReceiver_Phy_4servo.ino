#include <SPI.h>
#include <LoRa.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int degre1 = 120;
int degre2 = 120;
int degre3 = 120;
int degre4 = 120;

int counter = 0;

// Parameters you can play with :

int txPower = 16; // from 0 to 20, default is 14
int spreadingFactor = 12; // from 7 to 12, default is 12
long signalBandwidth = 125E3; // 7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3,41.7E3,62.5E3,125E3,250E3,500e3, default is 125E3
int codingRateDenominator=4; // Numerator is 4, and denominator from 5 to 8, default is 5
int preambleLength=20; // from 2 to 20, default is 8
String payload = "10"; // you can change the payload

#define SS 10
#define RST 8
#define DI0 6
#define BAND 872E6  // Here you define the frequency carrier

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Receiver");
  Serial.print("SetFrequency : ");
  Serial.print(BAND);
  Serial.println("Hz");
  Serial.print("SetSpreadingFactor : SF");
  Serial.println(spreadingFactor);
  

  SPI.begin();
  LoRa.setPins(SS,RST,DI0);

  

  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
 LoRa.setTxPower(txPower,1);
 LoRa.setSpreadingFactor(spreadingFactor);
 LoRa.setSignalBandwidth(signalBandwidth);
 LoRa.setCodingRate4(codingRateDenominator);
 LoRa.setPreambleLength(preambleLength);


 servo1.attach(3);
 servo2.attach(9);
 servo3.attach(7);
 servo4.attach(5);
}

void loop() {
   // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    String message;
    while (LoRa.available()) {
      //Serial.print((char)LoRa.read());
      message += (char)LoRa.read();
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    Serial.print("message: ");
    Serial.println(message);
    if (message == "1") {
      servo1.write(degre1);
      delay(100);
        if (degre1 == 60) {
          degre1 = 120;
        } else {
          degre1 = 60;
        }
     } 
     else if (message == "2") {
      servo2.write(degre2);
      delay(100);
        if (degre2 == 60) {
          degre2 = 120;
        } else {
          degre2 = 60;
        }
     } else if (message == "3") {
      servo3.write(degre3);
      delay(100);
        if (degre3 == 60) {
          degre3 = 120;
        } else {
          degre3 = 60;
        }
     } else if (message == "4") {
      servo4.write(degre4);
      delay(100);
        if (degre4 == 60) {
          degre4 = 120;
        } else {
          degre4 = 60;
        }
     }
  }
   
}




 
