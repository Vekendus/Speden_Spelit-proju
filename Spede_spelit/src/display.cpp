#include "display.h"

// PIN mappaus
const int PIN_RESET       = 12;
const int PIN_SHIFTCLK    = 11;
const int PIN_LATCHCLK    = 10;
const int PIN_OUTENABLE   = 9;
const int PIN_SERIALIN    = 8;

// Segment bitti patternit digiteille 0-9
const uint8_t digitMap[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

void initializeDisplay(void)
{
  pinMode(PIN_RESET, OUTPUT);       // Asettaa tarvittavat pinnit OUTPUT tilaan
  pinMode(PIN_SHIFTCLK, OUTPUT);
  pinMode(PIN_LATCHCLK, OUTPUT);
  pinMode(PIN_OUTENABLE, OUTPUT);
  pinMode(PIN_SERIALIN, OUTPUT);

  // Nollaa siirtorekisterin
  digitalWrite(PIN_RESET, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_RESET, HIGH);

  // Enabloi output (LOW = enabled)
  digitalWrite(PIN_OUTENABLE, LOW);
  
  //Näyttää 8 molemmilla segmenttinäytöillä 500ms delaylla
  writeHighAndLowNumber(8, 8);
  delay(500);
  
  //Nollaa näytöt
  writeHighAndLowNumber(0 , 0);
}


void writeByte(uint8_t number, bool last)
{
  uint8_t bits = digitMap[number];    // Hakee segmenttikoodin kartasta

  
  for (int i = 7; i >= 0; i--) {      // Siirtää 8 bittiä siirtorekisteriin
    bool bitVal = (bits >> i) & 1;
    digitalWrite(PIN_SERIALIN, bitVal);
    
    digitalWrite(PIN_SHIFTCLK, HIGH);
    digitalWrite(PIN_SHIFTCLK, LOW);
  }

  // Latch output jos last == true
  if (last) {
    digitalWrite(PIN_LATCHCLK, HIGH);
    digitalWrite(PIN_LATCHCLK, LOW);
  }
}


void writeHighAndLowNumber(uint8_t tens, uint8_t ones)
{
  writeByte(tens, false);
  writeByte(ones, true);
}

void showResult(byte result)
{
  uint8_t tens = result / 10;
  uint8_t ones = result % 10;

  writeHighAndLowNumber(tens, ones);
}

