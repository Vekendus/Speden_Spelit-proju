#include "buttons.h"

volatile int pressedButton = -1;

// Kertoo, onko napin painallus havaittu
bool buttonPressed = false;

// Tallentaa viimeisimmän painalluksen ajan millisekunteina
unsigned long lastPressTime = 0;

// Debounce-aika millisekunteina, varmaankin 50ms on riittävä aikaväli (?)
const int debounceTime = 50;

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
    if (digitalRead(2) == LOW)
    {
        return 0;
    }
    else if (digitalRead(3) == LOW)
    {
        return 1;
    }
    else if (digitalRead(4) == LOW)
    {
        return 2;
    }
    else if (digitalRead(5) == LOW)
    {
        return 3;
    }

    return -1;
}
ISR(PCINT2_vect)
{
        // Merkitään, että napin painallus on havaittu
        buttonPressed = true;

        // Tallennetaan tämänhetkinen aika millisekunteina
        lastPressTime = millis();
}

bool debounce()
{
    long currentTime= millis();
    if(currentTime-lastPressTime>debouncneTime){
        return true;
    }
    return false;
}

