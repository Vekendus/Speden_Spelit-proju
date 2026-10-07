#include menu.h

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

    for (int i = 0; i < 5; i++) {
        topFiveScores[i] = EEPROM.read(i);
    }

    startMenu();
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

            index++
            if (index >= 5) {
                index = 0;
            }
        }
    }
}