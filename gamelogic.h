#ifndef GAMELOGIC_H
#define GAMELOGIC_H

enum GameState {
  WAITING_TO_START,
  WAITING_FOR_RELEASE,
  SHOWING_TARGET,
  WAITING_FOR_BUTTON,
  GAME_OVER
};

void initializeGame(void);
void UpdateGaS(void);

#endif
