#include "leds.h"

//määritellään ledien pinnit
const uint8_t ledList[]={A2, A3, A4, A5};

void initializeLeds()
{
  int i;
  for(i=0; i<sizeof(ledList);i++)
  {    
    pinMode(ledList[i], OUTPUT);
  }
  testLeds();
}


void setLed(uint8_t ledNumber)
{
  digitalWrite(ledList[ledNumber], HIGH);
}


void clearLed(uint8_t ledNumber)
{
  digitalWrite(ledList[ledNumber], LOW);
}


void clearAllLeds()
{
  int i;
  for(i=0;i<sizeof(ledList);i++)
  {
    digitalWrite(ledList[i], LOW);
  }
}


void setAllLeds()
{
  int i;
  for(i=0;i<sizeof(ledList);i++)
  {
    digitalWrite(ledList[i], HIGH);
  }
}


void testLeds()
{
 int i;
  for(i=0;i<sizeof(ledList);i++)
  {
    setLed(0);
    delay(500);
    setLed(1);
    delay(500);
    setLed(2);
    delay(500);
    setLed(3);
    clearAllLeds();
    delay(500);
    setAllLeds();
    delay(200);
    clearAllLeds();
    setAllLeds();
    delay(200);
    clearAllLeds();
    
  }

}

void show1()
{
  uint8_t dataLimit=15;
  uint8_t data=0;
  uint8_t mask = 0b00000001;
  int bitCount=0;
  int delayTime=500;

  clearAllLeds();
  delay(delayTime);

  for(data=1;data<dataLimit;data++)
  {
    bitCount=0;
    for(mask=0b00000001; mask<=0b00001000; mask<<=1)
    {
      if(data & mask)
      {
        digitalWrite(ledList[bitCount], HIGH);
      }
      else
      {
        digitalWrite(ledList[bitCount], LOW);
      }
      bitCount++;
    }
    delay(delayTime);
  }
  setAllLeds();
  delay(delayTime);
}

void show2(int rounds)
{
  int i=0;
  int j=0;
  int delayTime=500;

  for(i=1; i<=rounds;i++)
  {
    clearAllLeds();
    delay(delayTime/i);

    for(j=0;j<sizeof(ledList);j++)
    {
      digitalWrite(ledList[j], HIGH);
      delay(delayTime/i);
    }
    
  }
}
