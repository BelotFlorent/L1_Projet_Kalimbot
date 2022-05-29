#include <SPI.h>
#include <LoRa.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;


int counter = 0;


int txPower = 14; // from 0 to 20, default is 14
int spreadingFactor = 12; // from 7 to 12, default is 12
long signalBandwidth = 250E3; // 7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3,41.7E3,62.5E3,125E3,250E3,500e3, default is 125E3
int codingRateDenominator=8; // Numerator is 4, and denominator from 5 to 8, default is 5
int preambleLength=20; // from 2 to 20, default is 8

#define SS 10
#define RST 8
#define DI0 6
#define BAND 

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
 servo3.attach(5);
 servo4.attach(7);
 servo5.attach(A3);
 servo6.attach(A0);
 servo7.attach(2);
 servo8.attach(A1);
}

void loop() {
   // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String message;
    while (LoRa.available()) {
      message += (char)LoRa.read();
    }

    Serial.print("message: ");
    Serial.print(message); 
    Serial.print("  RSSI ");
    Serial.println(LoRa.packetRssi());
    
    int degre1 = 110;
    int degre2 = 110;
    int degre3 = 80;
    int degre4 = 110;
    int degre5 = 80;
    int degre6 = 110;
    int degre7 = 70;
    int degre8 = 110;
    int delais = 500;
    int longueur = message.length();
    servo1.write(degre1);
    servo2.write(degre2);
    servo3.write(degre3);
    servo4.write(degre4);
    servo5.write(degre5);
    servo6.write(degre6);
    servo7.write(degre7);
    servo8.write(degre8);
    delay(2000);
    
    int i;
    for (i=0; i<longueur; i++) {
      Serial.println(message[i]);
      if ((String)message[i] == "1") {
        if (degre1 == 90) {
          degre1 = 110;
        } else {
          degre1 = 90;
        }
        servo1.write(degre1);
      delay(delais);
     } 
     else if ((String)message[i] == "2") {
        if (degre2 == 90) {
          degre2 = 110;
        } else {
          degre2 = 90;
        }
      servo2.write(degre2);
      delay(delais);
     } else if ((String)message[i] == "3") {
        if (degre3 == 80) {
          degre3 = 110;
        } else {
          degre3 = 80;
        }
      servo3.write(degre3);
      delay(delais);
     } else if ((String)message[i] == "4") {
        if (degre4 == 80) {
          degre4 = 110;
        } else {
          degre4 = 80;
        }
      servo4.write(degre4);
      delay(delais);
     } else if ((String)message[i] == "5") {
        if (degre5 == 80) {
          degre5 = 110;
        } else {
          degre5 = 80;
        }
      servo5.write(degre5);
      delay(delais);
     } else if ((String)message[i] == "6") {
        if (degre6 == 80) {
          degre6 = 110;
        } else {
          degre6 = 80;
        }
      servo6.write(degre6);
      delay(delais);
     } else if ((String)message[i] == "7") {
        if (degre7 == 70) {
          degre7 = 110;
        } else {
          degre7 = 70;
        }
      servo7.write(degre7);
      delay(delais);
     } else if ((String)message[i] == "8") {
        if (degre8 == 85) {
          degre8 = 110;
        } else {
          degre8 = 85;
        }
      servo8.write(degre8);
      delay(delais);
     } else if ((String)message[i] == "0") {
      delay(delais);
     }
    } 
  }
}




 
