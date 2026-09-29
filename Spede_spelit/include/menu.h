#ifndef MENU_H
#define MENU_H
#include <Arduino.h>
#include <EEPROM.h>
#include "leds.h"
#include "topScores.h"

/*
Menu-loopin alustus.
Nollataan ajastin.
Luetaan pisteet taulukkoon.
Kutsutaan startMenu()
*/

void initializeMenu(void);

/*
Käynnistetään menu-looppi.
Käynnistetään ensin initializeMenu().
While-loopissa jos timer-keskeytys tapahtuu,
vaihdetaan pisteet näytölle.
Napin painaminen breakaa ulos while-loopista.
Jatkuvasti pyörivän while-loopin voi tehdä esim.
while(1){}
*/
void startMenu(void);

#endif
