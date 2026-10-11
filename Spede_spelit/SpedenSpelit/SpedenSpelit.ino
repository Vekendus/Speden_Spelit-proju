#include "display.h"
#include "buttons.h"
#include "leds.h"
#include "gamelogic.h"
#include "menu.h"


// Use these 2 volatile variables for communicating between
// loop() function and interrupt handlers
volatile int buttonNumber = -1;           // for buttons interrupt handler
volatile bool newTimerInterrupt = false;  // for timer interrupt handler
extern bool buttonPressed;
extern uint8_t score;
extern unsigned long lastPressTime;
extern GameState gameState;
extern uint8_t topScores[5];
bool debounceOK;
bool gameOverFlag = false;
void setup()
{
  initializeDisplay();
  initializeLeds(); 
  initializeGame();

  initButtonsAndButtonInterrupts();
  Serial.begin(9600);
}

void loop()
{
  initializeMenu();
  startMenu();
  initializeGame();
  while(!gameOverFlag)
  {
    
    UpdateGaS();
  }
  
  gameOverFlag = false;
  checkScores(score, topScores);
  
}

