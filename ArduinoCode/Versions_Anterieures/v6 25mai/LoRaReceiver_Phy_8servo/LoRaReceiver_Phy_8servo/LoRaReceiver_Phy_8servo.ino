#include <SPI.h>
#include <LoRa.h>
#include <Servo.h>

//Initialistation des servomoteurs
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

// Parameters you can play with :

int txPower = 14; // from 0 to 20, default is 14
int spreadingFactor = 12; // from 7 to 12, default is 12
long signalBandwidth = 250E3; // 7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3,41.7E3,62.5E3,125E3,250E3,500e3, default is 125E3
int codingRateDenominator=8; // Numerator is 4, and denominator from 5 to 8, default is 5
int preambleLength=20; // from 2 to 20, default is 8

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
    int counter = 0;
    char delai;
    while (LoRa.available()) {
      if (counter < 3) {
        delai += (char)LoRa.read();
      } else {
        message += (char)LoRa.read();
      }
      counter++;
    }
    int delais = atoi(delai);
    Serial.print("message: ");
    Serial.print(message); 
    Serial.print("  RSSI ");
    Serial.println(LoRa.packetRssi());
    
    int degre1 = 108;
    int degre2 = 120;
    int degre3 = 120;
    int degre4 = 120;
    int degre5 = 120;
    int degre6 = 120;
    int degre7 = 120;
    int degre8 = 120;
    int longueur = message.length();
    servo1.write(degre1);
    servo2.write(degre2);
    servo3.write(degre3);
    servo4.write(degre4);
    servo5.write(degre5);
    servo6.write(degre6);
    servo7.write(degre7);
    servo8.write(degre8);
    delay(1000);
    
    int i;
    for (i=0; i<longueur; i++) {
      Serial.println(message[i]);
      if ((String)message[i] == "1") {
        if (degre1 == 75) {
          degre1 = 108;
        } else {
          degre1 = 75;
        }
        servo1.write(degre1);
      delay(delais);
     } 
     else if ((String)message[i] == "2") {
        if (degre2 == 60) {
          degre2 = 120;
        } else {
          degre2 = 60;
        }
      servo2.write(degre2);
      delay(delais);
     } else if ((String)message[i] == "3") {
        if (degre3 == 60) {
          degre3 = 120;
        } else {
          degre3 = 60;
        }
      servo3.write(degre3);
      delay(delais);
     } else if ((String)message[i] == "4") {
        if (degre4 == 60) {
          degre4 = 120;
        } else {
          degre4 = 60;
        }
      servo4.write(degre4);
      delay(delais);
     } else if ((String)message[i] == "5") {
        if (degre5 == 60) {
          degre5 = 120;
        } else {
          degre5 = 60;
        }
      servo5.write(degre5);
      delay(delais);
     } else if ((String)message[i] == "6") {
        if (degre6 == 60) {
          degre6 = 120;
        } else {
          degre6 = 60;
        }
      servo6.write(degre6);
      delay(delais);
     } else if ((String)message[i] == "7") {
        if (degre7 == 60) {
          degre7 = 120;
        } else {
          degre7 = 60;
        }
      servo7.write(degre7);
      delay(delais);
     } else if ((String)message[i] == "8") {
        if (degre8 == 60) {
          degre8 = 120;
        } else {
          degre8 = 60;
        }
      servo8.write(degre8);
      delay(delais);
     } else if ((String)message[i] == "0") {
      delay(delais);
     }
    } 
  }
}




 
