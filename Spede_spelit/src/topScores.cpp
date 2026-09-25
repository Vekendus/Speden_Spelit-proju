#include "topScores.h"
#include <EEPROM.h>

void readScores(int scores[], size_t listSize)
{
  size_t i=0;
  size_t address=0; //käytetään EEPROM:n muistipaikkana
  size_t itemSize;

  //selvitetään taulukon alkioiden koko, jotta osataan tallentaa oikein EEPROM-muistiin
  itemSize = sizeof(scores[0]); 

  for(i=0; i< listSize; i++)
  {
    address = i*itemSize;
    EEPROM.get(address, scores[i]);
  }
}

void updateScores(int score, int position)
{
  size_t address=0; //käytetään EEPROM:n muistipaikan osoittamiseen
  size_t itemSize;

  //otetaan scoren koko oikeaan muistipaikkaan kirjoittamista varten
  itemSize = sizeof(score);

    address = position*itemSize;
    EEPROM.put(address, score);
  
}