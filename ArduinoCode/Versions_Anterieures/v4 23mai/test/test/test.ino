#include "lcdgfx.h"
#include <stdlib.h>

const int milieu  = A2;
const int gauche  = A1;
const int droite  = A3;
int btnValMilieu  = 0;
int btnValGauche  = 0;
int btnValDroite  = 0;
int curseur = 1;
int curseur2 = 1;
int nombreMusique = 2;
//String nomMusique[2] = {"Au clair  de la lune" ,"Twinkle twinkle little star"};
//String Musique[2] = {"1112302013221", "11556650443322105544332055443320115566504433221"};

DisplaySSD1306_128x64_I2C display(-1);

void setup(){
//Boutons 
    Serial.begin(115200);
    Serial.println(F("Initialize System"));
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
 
 if (curseur == 1 && curseur2 != 1) {
  curseur2 = 1;
  display.clear();
  display.printFixedN (0,  16, "Au clair  de la lune", STYLE_NORMAL, FONT_SIZE_2X);
  if (btnValMilieu<200) {
    Serial.println(F("1112302013221"));
    delay(300);
  }
 } else if (curseur == 2 && curseur2 != 2) {
  curseur2 = 2;
  display.clear();
  display.printFixedN (0,  16, "Twinkle twinkle little star", STYLE_NORMAL, FONT_SIZE_2X);
  if (btnValMilieu<200) {
    Serial.println(F("11556650443322105544332055443320115566504433221"));
    delay(300);
  }
 }
 if (btnValGauche<200){
   curseur--;
   if (curseur < 1) {
    curseur = nombreMusique;
   }
   delay(300);
 } if(btnValDroite<200){
   curseur++;
   if (curseur > nombreMusique) {
    curseur = 1;
   }
   delay(300);
 }

}
