#ifndef TOPSCORES_H
#define TOPSCORES_H
#include <Arduino.h>
#include <EEPROM.h>

/*
readScores-funktio lukee taulukkoon top-pisteet EEPROM:sta.
Funktio ottaa argumenttina taulukon, johon tiedot luetaan, sekä taulukon koon.
HUOM! Argumenttina otettu taulukko on osoitin ensimmäiseen alkioon, joten tarvitaan myös koko.
*/
void readScores(int scores[], size_t listSize);

/*
updateScores-funktio päivittää pisteet EEPROM:iin.
Funktio ottaa argumenttina taulukon, josta tiedot päivitetään, sekä taulukon koon.
HUOM! Argumenttina otettu taulukko on osoitin ensimmäiseen alkioon, joten tarvitaan myös koko.
*/
void updateScores(int score, int position);

//Nollataan pistetilasto
void resetScores(void);

#endif
