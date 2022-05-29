#include "lcdgfx.h"
#include <SPI.h>
#include <LoRa.h>

const int milieu  = A2;
const int gauche  = A1;
const int droite  = A3;
int btnValMilieu  = 0;
int btnValGauche  = 0;
int btnValDroite  = 0;
int curseur = 1;
int curseur2 = 1;
int nombreMusique = 2;

DisplaySSD1306_128x64_I2C display(-1);

int txPower = 14; // from 0 to 20, default is 14
int spreadingFactor = 12; // from 7 to 12, default is 12
long signalBandwidth = 125E3; // 7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3,41.7E3,62.5E3,125E3,250E3,500e3, default is 125E3
int codingRateDenominator=8; // Numerator is 4, and denominator from 5 to 8, default is 5
int preambleLength=8; // from 2 to 20, default is 8
String payload = "1";

#define SS 10
#define RST 8
#define DI0 3
#define BAND 872E6

void setup(){
//Boutons 
  Serial.begin(115200);
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

 


    
    pinMode(milieu,INPUT_PULLUP);
    pinMode(gauche,INPUT_PULLUP);
    pinMode(droite,INPUT_PULLUP);
    display.begin();
    display.fill(0x00);
    display.setFixedFont(ssd1306xled_font6x8);
    display.printFixedN (0,  16, "Au clair  de la lune", STYLE_NORMAL, FONT_SIZE_2X);
    

}
void loop() {
 ////Read pushbutton 
 btnValMilieu=analogRead(milieu);
 btnValGauche=analogRead(gauche);
 btnValDroite=analogRead(droite);
 
 if (curseur == 1) {
  if (curseur2 != 1) {
    curseur2 = 1;
    display.clear();
    display.printFixedN (0,  16, "Au clair  de la lune", STYLE_NORMAL, FONT_SIZE_2X);
  }
  if (btnValMilieu<200) {
    LoRa.beginPacket();
    LoRa.print("1112302013221");  
    LoRa.endPacket();
    Serial.print("1112302013221");
    delay(800);
  }
 } else if (curseur == 2) {
  if (curseur2 != 2) {
    curseur2 = 2;
  display.clear();
  display.printFixedN (0,  16, "Twinkle twinkle little star", STYLE_NORMAL, FONT_SIZE_2X);
  }
  
  if (btnValMilieu<200) {
    LoRa.beginPacket();
    LoRa.print("11556650443322105544332055443320115566504433221");  
    LoRa.endPacket();
    Serial.print("11556650443322105544332055443320115566504433221");
    delay(800);
  }
 }
 if (btnValGauche<200){
   curseur--;
   if (curseur < 1) {
    curseur = nombreMusique;
   }
   delay(800);
 } if(btnValDroite<200){
   curseur++;
   if (curseur > nombreMusique) {
    curseur = 1;
   }
   delay(800);
 }

}
