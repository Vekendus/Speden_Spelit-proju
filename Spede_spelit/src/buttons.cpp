#include "buttons.h"

volatile int pressedButton = 0;

/* 
hieman parempi koodaustapa voisi olla käyttää const int -muuttujia pinnien määrityksenä,
sitten viitata muuttujalla pinmodessa.
*/

void initButtonsAndButtonInterrupts(void)
{
  // See requirements for this function from buttons.h
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);

    // PCINT2-ryhmän keskeytykset käyttöön, siirretään 1 bitti rekisterissä 0:sta -> 1:een
    PCICR |= (1 << PCIE2);

    // Pinnien 2–5 pin-change-keskeytykset käyttöön siirtämällä 1 bitti rekisterissä 0 -> 1
    PCMSK2 |= (1 << PCINT18);  // pin 2
    PCMSK2 |= (1 << PCINT19);  // pin 3
    PCMSK2 |= (1 << PCINT20);  // pin 4
    PCMSK2 |= (1 << PCINT21);  // pin 5
}

ISR(PCINT2_vect)
{
  /*
  Käytä booleania, jolla tunnistetaan, että jonkin napin tila on muuttunut.
  Ota aikaleima millis()-funktiolla. Aikaleiman avulla voidaan pelissä määrittää, onko kyse värähtelystä vai 
  */
}

/* Tarkista myös buttons.h lisähuomiot! */
