#ifndef DISPLAY_H
#define DISPLAY_H
#include <Arduino.h>

/*
  Alusta pinnit 8-12.
  Näytä näytöillä luku 8 esim. 500ms, jotta näkee, että kaikki segmentit kunnossa.
  HUOM! Voit hyödyntää writeHighAndLowNumber()-funktiota.
  Delayn jälkeen lähetä arvoiksi nollat, jolloin näytöt "alustuvat"
*/
void initializeDisplay(void);

/*
Muuta saatu numero biteiksi ja lähetä hc595-rekisterille.
Jos ei ole vielä viimeinen numero, jää odottamaan seuraavaa numeroa.
Jos on viimeinen numero, näytä pisteet näytöillä.
*/
void writeByte(uint8_t number, bool last);

/*
Välitä writeByte-funktiolle ensin kympit.
bool last pitää olla false.
Sen jälkeen välitä ykköset ja last = true.
*/
void writeHighAndLowNumber(uint8_t tens,uint8_t ones);

/*
  Jaa pistemäärä kymppeihin ja ykkösiin. Kympit saa jakolaskulla, ykköset jakojäännöksellä.
  Välitä tulokset writeHighAndLowNumber()-funktiolle
*/
void showResult(byte result);

#endif
