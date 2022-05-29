#include "lcdgfx.h"
#include <SPI.h>
#include <LoRa.h>

//On initialise les variables utilisé par les boutons
const int milieu  = A2;
const int gauche  = A1;
const int droite  = A3;
int btnValMilieu  = 0;
int btnValGauche  = 0;
int btnValDroite  = 0;
int curseur = 1; //Le curseur sert a savoir quel musique doit être afficher sur l'écran
int curseur2 = 1; //Cette variable permet de savoir si on vient d'arriver sur une nouvelle musique donc si on doit clear l'écran puis l'afficher ou si on regarde juste si elle doit être joué.
int nombreMusique = 7;

DisplaySSD1306_128x64_I2C display(-1);

int txPower = 14; // from 0 to 20, default is 14
int spreadingFactor = 12; // from 7 to 12, default is 12
long signalBandwidth = 250E3; // 7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3,41.7E3,62.5E3,125E3,250E3,500e3, default is 125E3
int codingRateDenominator=8; // Numerator is 4, and denominator from 5 to 8, default is 5
int preambleLength=20; // from 2 to 20, default is 8
String payload = "1"; // you can change the payload

#define SS 10
#define RST 8
#define DI0 3
#define BAND 872E6


void setup(){
  //Setup LoRa
  
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

 


    //Boutons
    pinMode(milieu,INPUT_PULLUP);
    pinMode(gauche,INPUT_PULLUP);
    pinMode(droite,INPUT_PULLUP);

    //Écran
    display.begin();
    display.fill(0x00);
    display.setFixedFont(ssd1306xled_font6x8);
    display.printFixedN (0,  16, "Au clair  de la lune", STYLE_NORMAL, FONT_SIZE_2X);
    

}
void loop() {
 ////On lit la valeur des boutons
 btnValMilieu=analogRead(milieu);
 btnValGauche=analogRead(gauche);
 btnValDroite=analogRead(droite);
 
 //On ne peut pas mettre de variable dans la fonction display.printFixedN de l'écran du coup j'ai du fait avec des if à la suite.
 if (curseur == 1) { //On regarde la valeur du curseur donc la musique sur laquelle nous nous situons
  if (curseur2 != 1) {//On vérifie si on est déjà sur la musique ou si on vient d'y arriver.
    curseur2 = 1;
    display.clear();
    display.printFixedN (0,  16, "Au clair  de la lune", STYLE_NORMAL, FONT_SIZE_2X);
  }
  //On verifie si la boutons du milieu a été enclanché
  if (btnValMilieu<200) {
    //On envoie et affiche la suite de note a jouer.
    LoRa.beginPacket();
    LoRa.print("51112302013221");  
    LoRa.endPacket();
    Serial.print("51112302013221");
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
    LoRa.print("411556650443322105544332055443320115566504433221");  
    LoRa.endPacket();
    Serial.print("411556650443322105544332055443320115566504433221");
    delay(800);
  }
 } else if (curseur == 3) {
  if (curseur2 != 3) {
    curseur2 = 3;
  display.clear();
  display.printFixedN (0,  16, "C418      Haggstrom", STYLE_NORMAL, FONT_SIZE_2X);
  }
  
  if (btnValMilieu<200) {
    LoRa.beginPacket();
    LoRa.print("5821821682182108218216821821");  
    LoRa.endPacket();
    Serial.print("5821821682182108218216821821");
    delay(800);
  }
 } else if (curseur == 4) {
  if (curseur2 != 4) {
    curseur2 = 4;
  display.clear();
  display.printFixedN (0,  16, "Fairy's   Glitter", STYLE_NORMAL, FONT_SIZE_2X);
  }
  
  if (btnValMilieu<200) {
    LoRa.beginPacket();
    LoRa.print("4432065604554586054504056543213121");  
    LoRa.endPacket();
    Serial.print("4432065604554586054504056543213121");
    delay(800);
  }
 } else if (curseur == 5) {
  if (curseur2 != 5) {
    curseur2 = 5;
  display.clear();
  display.printFixedN (0,  16, "Children  lullaby", STYLE_NORMAL, FONT_SIZE_2X);
  }
  
  if (btnValMilieu<200) {
    LoRa.beginPacket();
    LoRa.print("467576660777066606757666077675");  
    LoRa.endPacket();
    Serial.print("467576660777066606757666077675");
    delay(800);
  }
 } else if (curseur == 6) {
  if (curseur2 != 6) {
    curseur2 = 6;
  display.clear();
  display.printFixedN (0,  16, "La vie en rose", STYLE_NORMAL, FONT_SIZE_2X);
  }
  
  if (btnValMilieu<200) {
    LoRa.beginPacket();
    LoRa.print("38007653870065317600532176005");  
    LoRa.endPacket();
    Serial.print("38007653870065317600532176005");
    delay(800);
  }
 } else if (curseur == 7) {
  if (curseur2 != 7) {
    curseur2 = 7;
  display.clear();
  display.printFixedN (0,  16, "Mad World", STYLE_NORMAL, FONT_SIZE_2X);
  }
  
  if (btnValMilieu<200) {
    LoRa.beginPacket();
    LoRa.print("422442266060400550503005505043200224422660604005505030055050432002244667505775520024466750577552");  
    LoRa.endPacket();
    Serial.print("422442266060400550503005505043200224422660604005505030055050432002244667505775520024466750577552");
    delay(800);
  }
 }
 //On cherche a savoir si le bouton gauche ou droit on été enclenché si oui on change la valeur du curseur pour aller vers la musique suivante ou précédente.
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
