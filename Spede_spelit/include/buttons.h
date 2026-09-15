#ifndef BUTTONS_H
#define BUTTONS_H
#include <arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>


const byte firstPin = 2; // First PinChangeInterrupt on D-bus
const byte lastPin =  5; // Last PinChangeInterrupt on D-bus

/* 
  initButtonsAndButtonInterrupts subroutine is called from Setup() function
  during the initialization of Speden Spelit. This function does the following:
  1) Initializes 4 button pins for the game = Arduino pins 2,3,4,5
  2) Initializes 1 button pin for starting the game = Aruino pin 6
  3) Enables PinChangeInterrupt on D-bus in a way that interrupt
     is generated whenever some of pins 2,3,4,5,6 is connected to LOW state

*/
void initButtonsAndButtonInterrupts(void);

/*
Koska PCINT-keskeytys tunnistaa vain, että jotain ryhmän nappia on painettu,
voisi olla aiheellista määrittää myös funktio, jolla nappi tunnistetaan, esim. int checkPressedButton().
PIND antaa ryhmän pinnien hetkellisen tilan binäärinä.
Pinnit 2-5 ovat määritelty PD2-PD5. Vertaamalla PD:tä ja PIND:iä voidaan todeta, mikä nappi on pohjassa.
HUOM! Jos esim. vertailu PIND & 1 << PD3 = true, pinnin 3 nappi on ylhäällä, eikä painettuna. 
Mikäli nappia on painettu (pind ja pd:n vertailu tuottaa false), palauta nappia vastaava arvo.
pin2 = 0
pin3 = 1
pin4 = 2
pin5 = 3
muutoin palauta -1
*/

// Intoduce PCINT2_vect Interrupt SeRvice (ISR) function for Pin Change Interrupt.
ISR(PCINT2_vect); 
#endif;
