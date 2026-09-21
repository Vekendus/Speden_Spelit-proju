#include "buttons.h"

volatile int pressedButton = -1;

void initButtonsAndButtonInterrupts(void)
{

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
int checkPressedButton(void)
{
    // PIND sisältää PORTD-pinnien hetkelliset(?) tilat 
     // Luetaan PORTD-rekisteristä pinni 2
    // Jos PD2 on LOW, pin 2:n nappi on painettu, sama muille 
    if (!(PIND & (1 << PD2)))
    {
        return 0;
    }
    else if (!(PIND & (1 << PD3)))
    {
        return 1;
    }
    else if (!(PIND & (1 << PD4)))
    {
        return 2;
    }
    else if (!(PIND & (1 << PD5)))
    {
        return 3;
    }

    return -1;
}
ISR(PCINT2_vect)
{
 
   pressedButton = checkPressedButton(); // Selvitetään, mikä nappi aiheutti keskeytyksen
  
    if (pressedButton != -1)// Tarkistetaan, löytyikö painettu nappi
    {
       
        buttonPressed = true; // Merkitään, että napin painallus on havaittu

       
        lastPressTime = millis(); // Tallennetaan tämänhetkinen aika millisekunteina
    }
}

