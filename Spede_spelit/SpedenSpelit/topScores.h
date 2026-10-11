#ifndef TOPSCORES_H
#define TOPSCORES_H
#include <Arduino.h>
#include <EEPROM.h>

/*
readScores-funktio lukee taulukkoon top-pisteet EEPROM:sta.
Funktio ottaa argumenttina taulukon, johon tiedot luetaan, sekä taulukon koon.
HUOM! Argumenttina otettu taulukko on osoitin ensimmäiseen alkioon, joten tarvitaan myös koko.
*/
void readScores(uint8_t scores[], size_t listSize);

/*
updateScores-funktio päivittää pisteet EEPROM:iin.
Funktio ottaa argumenttina pistemäärän, sekä pistetaulukon indeksin.
*/
void updateScore(uint8_t score, int index);

void checkScores(uint8_t score, uint8_t scoreboard[]);
//Nollataan pistetilasto
void resetScores(void);

#endif
