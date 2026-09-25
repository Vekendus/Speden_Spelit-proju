#include "topScores.h"
#include <EEPROM.h>

/**************************************************************/
/* This code if for an Arduino school project.                */
/* Code reads top scores from EEPROM and updates top scores.  */
/* In EEPROM address 0 is the best result.                    */
/* Written by: Niko Siironen, 2026.                           */
/**************************************************************/

void readScores(int scores[], size_t listSize)
{
  size_t i=0;
  size_t address=0; //käytetään EEPROM:n muistipaikkana
  size_t itemSize;

  //selvitetään taulukon alkioiden koko tavuina, jotta osataan tallentaa oikein EEPROM-muistiin.
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
