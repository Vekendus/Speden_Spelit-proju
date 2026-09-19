#include "leds.h"

//määritellään ledien pinnit
const uint8_t ledList[]={A2, A3, A4, A5};

void initializeLeds()
{
  int i;
  int numberOfLeds =0;
  numberOfLeds=sizeof(ledList);
  
  for(i=0; i<numberOfLeds;i++)
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
  int numberOfLeds =0;
  numberOfLeds=sizeof(ledList);
  
  for(i=0; i<numberOfLeds;i++)
  {
    digitalWrite(ledList[i], LOW);
  }
}


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
        setLed(ledList[bitCount]);
      }
      else
      {
        clearLed(ledList[bitCount]);
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
  int numberOfLeds =0;
  numberOfLeds=sizeof(ledList);

  for(i=1; i<=rounds;i++)
  {
    clearAllLeds();
    delayTime=delayTime/i;
    delay(delayTime);

    for(j=0;j<numberOfLeds;j++)
    {
      digitalWrite(ledList[j], HIGH);
      delay(delayTime);
    }
    
  }
}
