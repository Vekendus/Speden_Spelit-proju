#include "leds.h"

/**************************************************************/
/* This code if for an Arduino school project.                */
/* Code sets and clears leds as needed.                       */
/* Written by: Niko Siironen, 2026.                           */
/**************************************************************/

//määritellään ledien pinnit
const uint8_t ledList[]={A2, A3, A4, A5};

void initializeLeds()
{
  int i;
  int numberOfLeds =0;
  numberOfLeds=sizeof(ledList); //tarkistetaan ledien määrä määritellyistä pinneistä
  
  for(i=0; i<numberOfLeds;i++)
  {    
    pinMode(ledList[i], OUTPUT);
  }
  testLeds(numberOfLeds);
}

//sytytetään yksittäinen ledi
void setLed(uint8_t ledNumber)
{
  digitalWrite(ledList[ledNumber], HIGH);
}

//sammutetaan yksittäinen ledi
void clearLed(uint8_t ledNumber)
{
  digitalWrite(ledList[ledNumber], LOW);
}

//sammutetaan kaikki ledit
void clearAllLeds()
{
  int i;
  int numberOfLeds =0;
  numberOfLeds=sizeof(ledList);
  
  for(i=0; i<numberOfLeds;i++)
  {
    digitalWrite(ledList[i], LOW);
  }
}

//sytytetään kaikki ledit
void setAllLeds()
{
  int i;
  int numberOfLeds =0;
  numberOfLeds=sizeof(ledList);
  
  for(i=0; i<numberOfLeds;i++)
  {
    digitalWrite(ledList[i], HIGH);
  }
}

//ledien toimivuuden testaus
void testLeds(uint8_t numberOfLeds)
{
 int i;
  int delayTime=200;
  
  for(i=0;i<numberOfLeds;i++)
  {
    setLed(i);
    delay(delayTime);
  }

  for(i=1; i<=2; i++)
  {
    clearAllLeds();
    delay(delayTime);
    setAllLeds();
    delay(delayTime);
  }
  
  clearAllLeds();

}

//muutetaan luvut 0-15 binäärimuotoon ja sytytetään asianmukaiset ledit.
void show1()
{
  uint8_t dataLimit=15;
  uint8_t data=0; //muuttujaan otetaan luvut 0 - dataLimit
  uint8_t mask = 0b00000001; //maski lukujen läpikäyntiin
  int bitCount=0; //lasketaan, missä bitissä ollaan menossa, hyödynnetään ledien sytytysfunktioissa
  int delayTime=500;

  clearAllLeds();
  delay(delayTime);

  for(data=1;data<dataLimit;data++)
  {
    bitCount=0;
    for(mask=0b00000001; mask<=0b00001000; mask<<=1) //siirretään maskin bittiä vasemmalle yhden bitin verran
    {
      if(data & mask)
      {
        setLed(bitCount);
      }
      else
      {
        clearLed(bitCount);
      }
      bitCount++;
    }
    delay(delayTime);
  }
  setAllLeds();
  delay(delayTime);
}

//sytytetään vuorollaan jokainen ledi, tehdään annetun määrän kierroksia, jokaisella kierroksella nopeutetaan sytytystä
void show2(int rounds)
{
  int i=0; //apumuuttuja kierroksille
  int j=0; //apumuuttuja sytytettävälle ledille
  int delayTime=500;
  int numberOfLeds =0;
  numberOfLeds=sizeof(ledList);
  

  for(i=1; i<=rounds;i++)
  {
    clearAllLeds();
    delayTime=delayTime/i;
    delay(delayTime);

    for(j=0;j<numberOfLeds;j++)
    {
      setLed(j);
      delay(delayTime);
    }
    
  }
}
