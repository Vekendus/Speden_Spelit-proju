#include <Arduino.h>
#include "gamelogic.h"
#include "buttons.h"
#include "display.h"
#include "leds.h"
//asetetaan ohjelman tila:
static GameState gameState = WAITING_TO_START;

static uint8_t score = 0;
static uint8_t targetLed = 0;
static unsigned long targetShownAt = 0;
// Asetetaan reagointi raja:
static unsigned long responseTimeLimit = 1500;
/*--------------------------------------------------------

*/
static void startGame(void)
{
  score = 0;
  responseTimeLimit = 1500;
  clearAllLeds();
  gameState = WAITING_FOR_RELEASE;
}
/*--------------------------------------------------------

*/
static void waitForStart(void)
{
  if (debounce() && checkPressedButton() >= 0) {
    startGame();
  }
}
/*--------------------------------------------------------
Odotetaan että nappi on vapautettu eikä vain painettu:*/
static void waitForButtonRelease(void)
{
  if (debounce() && checkPressedButton() == -1) {
    gameState = SHOWING_TARGET;
  }
}
/*--------------------------------------------------------
Näytetään kohde ledi ja jäädään odottamaan napin painallusta*/
static void showTarget(void)
{
  targetLed = random(4);
  setLed(targetLed);
  targetShownAt = millis();
  gameState = WAITING_FOR_BUTTON;
}
/*--------------------------------------------------------
System checks player input and other variables concerning it.
*/
static void checkPlayerInput(void)
{
  if (millis() - targetShownAt >= responseTimeLimit) {
    finishGame();
    return;
  }

  if (!debounce()) {
    return;
  }

  int pressedButton = checkPressedButton();
  if (pressedButton < 0) {
    return;
  }

  if (pressedButton != targetLed) {
    finishGame();
    return;
  }

  clearLed(targetLed);
  if (score < 99) {
    score++;
  }
  if (responseTimeLimit > 300) {
    responseTimeLimit -= 50;
  }
  gameState = WAITING_FOR_RELEASE;
}
/*--------------------------------------------------------
System ends the game 
*/
static void finishGame(void)
{
  clearAllLeds();
  gameState = GAME_OVER;
}

/*--------------------------------------------------------
Gameover screen
*/
static void waitAfterGameOver(void)
{
  showResult(score);
  if (debounce() && checkPressedButton() >= 0) {
    startGame();
  }
}
/*--------------------------------------------------------

*/
void initializeGame(void)
{
  score = 0;
  responseTimeLimit = 1500;
  clearAllLeds();
  gameState = WAITING_TO_START;
}
/*--------------------------------------------------------

*/
void UpdateGaS(void)
{
  switch (gameState) {
    case WAITING_TO_START:
      waitForStart();
      break;

    case WAITING_FOR_RELEASE:
      waitForButtonRelease();
      break;

    case SHOWING_TARGET:
      showTarget();
      break;

    case WAITING_FOR_BUTTON:
      checkPlayerInput();
      break;

    case GAME_OVER:
      waitAfterGameOver();
      break;
  }
}
//--------------------------------------------------------