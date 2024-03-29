#include <SPI.h>
#include <LoRa.h>
#include <Servo.h>

Servo myservo9;
Servo myservo7;
int degre = 120;
int degre7 = 120;

int counter = 0;

// Parameters you can play with :

int txPower = 16; // from 0 to 20, default is 14
int spreadingFactor = 12; // from 7 to 12, default is 12
long signalBandwidth = 125E3; // 7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3,41.7E3,62.5E3,125E3,250E3,500e3, default is 125E3
int codingRateDenominator=4; // Numerator is 4, and denominator from 5 to 8, default is 5
int preambleLength=20; // from 2 to 20, default is 8
String payload = "10"; // you can change the payload

#define SS 10
#define RST 7
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


 myservo9.attach(9);
 myservo7.attach(7);
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
      myservo9.write(degre);
      delay(2000);
        if (degre == 60) {
          degre = 120;
        } else {
          degre = 60;
        }
     } 
     else if (message == "2") {
      myservo7.write(degre7);
      delay(2000);
        if (degre7 == 60) {
          degre7 = 120;
        } else {
          degre7 = 60;
        }
     }
  }
   
}




 
