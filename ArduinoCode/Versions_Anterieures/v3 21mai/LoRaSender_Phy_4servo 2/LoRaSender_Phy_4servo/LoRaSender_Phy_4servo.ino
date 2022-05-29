#include <SPI.h>
#include <LoRa.h>

int counter = 0;

// Parameters you can play with :

int txPower = 14; // from 0 to 20, default is 14
int spreadingFactor = 12; // from 7 to 12, default is 12
long signalBandwidth = 250E3; // 7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3,41.7E3,62.5E3,125E3,250E3,500e3, default is 125E3
int codingRateDenominator=8; // Numerator is 4, and denominator from 5 to 8, default is 5
int preambleLength=20; // from 2 to 20, default is 8
String payload = "1"; // you can change the payload

#define SS 10
#define RST 8
#define DI0 3
#define BAND 872E6  // Here you define the frequency carrier

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Sender");
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
// LoRa.setPolarity(1);
 //LoRa.setFSK(); 
 
}

void loop() {
  
  
  if (payload == "1") {
    payload = "2";
  }
  else if (payload == "2") {
    payload = "3";
  } else if (payload == "3") {
    payload = "4";
  } else if (payload == "4") {
    payload = "1";
  } else {
    payload = "1";
  }
  // send packet
  payload = "1112302013221";
  LoRa.beginPacket();
  LoRa.print(payload);  
  LoRa.endPacket();
  counter++;

  Serial.print("Sending packet with payload {");
  Serial.print(payload);
  Serial.print("} N°");
  Serial.println(counter);
 

  delay(1000000000000000);
}
