#include "menu.h"
#include "topScores.h"
extern void showCountdown();
extern void showTopFive(const uint8_t scores[5]);
extern void writeHighAndLowNumber(uint8_t tens, uint8_t ones);

const int PIN_BUTTON = 7;

volatile bool timerFLAG = false;

uint8_t topScores[5];

ISR(TIMER1_COMPA_vect)
{
  timerFLAG = true;
}

void initializeMenu()
{
    timerFLAG = false;

    readScores(topScores, 5);
    TCCR1A = 0;                 // Normaali porttitoiminta
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 15624;              // 16 MHz / 1024 / (15624 + 1) = 1 Hz
  TCCR1B |= (1 << WGM12);     // CTC-tila
  TCCR1B |= (1 << CS12) | (1 << CS10); // Esijakaja 1024
  TIMSK1 |= (1 << OCIE1A);    // Salli vertailukeskeytys A
}

void startMenu()
{
    pinMode(PIN_BUTTON, INPUT_PULLUP);

    int index = 0;
    bool showState = false;

    while (1)
    {
        if (digitalRead(PIN_BUTTON) == LOW) {
            break;
        }

        if (timerFLAG) {
            timerFLAG = false;
            showState = !showState;

            uint8_t score = topScores[index];
            uint8_t tens = score / 10;
            uint8_t ones = score % 10;

            writeHighAndLowNumber(tens, ones);

            index++;
            if (index >= 5) {
                index = 0;
            }
        }
    }
}
