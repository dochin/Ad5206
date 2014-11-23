/*AD5206 Driver Example

Purpose: Write values to and AD5206 connected through hardware SPI

Author: JGC
HWVER: DRKTRD-06

Changelog:
5/17/14 Cleaned up variables
5/17/14 Converted arduino example program to a library

Notes: Hardware SPI pins needed are 13:Clock, 11:MOSI
      the adcChipSelectPin is read in to the constructor

*/

#ifndef Ad5206_h
#define Ad5206_h

#include "Arduino.h"
#include "SPI.h"

class Ad5206 {
  public:
    Ad5206(byte slaveSelectPin);
    void write(byte address, byte value);
  private:
    byte _slaveSelectPin;
};

#endif
