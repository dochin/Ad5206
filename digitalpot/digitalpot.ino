/*
AD5206 Driver Example

Purpose: Write values to and AD5206 connected through hardware SPI

Author: Jason Campbell

Changelog:
5/17/14 Converted arduino example program to a library

Notes:

  Wiper is connected to A when value = 255, connected to B when value = 0.
  This is reversed from what most diagrams of physical pots indicates.

  !!!This program and driver are heavily based on the Arduino DigitalPotWrite 
  example program by Tom Igoe, 10 Aug 2010:
        ========================================================
        This example controls an Analog Devices AD5206 digital potentiometer.
        The AD5206 has 6 potentiometer channels. Each channel's pins are labeled
        A - connect this to voltage
        W - this is the pot's wiper, which changes when you set it
        B - connect this to ground.
       
       The AD5206 is SPI-compatible,and to command it, you send two bytes, 
       one with the channel number (0 - 5) and one with the resistance value for the
       channel (0 - 255).  
       
       The circuit:
        * All A pins  of AD5206 connected to +5V
        * All B pins of AD5206 connected to ground
        * An LED and a 220-ohm resisor in series connected from each W pin to ground
        * CS - to digital pin 10  (SS pin)
        * SDI - to digital pin 11 (MOSI pin)
        * CLK - to digital pin 13 (SCK pin)
       
         created 10 Aug 2010 
         by Tom Igoe
         
         Thanks to Heather Dewey-Hagborg for the original tutorial, 2005
       ==============================================
       
  Usage:
  ======
  Ad5206 myDigitalPot(slaveSelectPin); //Call constructor
  myDigitalPot.write(channel, value); //Channel is 0-5, value is 0-255.
  
*/

#include <SPI.h>  //This driver relies on SPI
#include "Ad5206.h"

// set pin 10 as the slave select for the digital pot:
const byte slaveSelectPin = 10;

// Set up some values for easier testing
const int waitTime = 1;
const byte channel = 0;

// Initialize the digital pot
Ad5206 myDigitalPot(slaveSelectPin);

void setup() {

}

void loop() {
   // change the resistance on the specified channel from min to max:
   for (byte level = 0; level < 255; level++) {
      myDigitalPot.write(channel, level);
      delay(waitTime);
    }
    // then back from max to min
    for (byte level = 255; level >0 ; level--) {
      myDigitalPot.write(channel, level);
      delay(waitTime);
    }
}


