#include <Arduino.h>
#include "leds.h"


// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  void initializeLeds();
  
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
//Main menu koodi



//peli koodi
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}