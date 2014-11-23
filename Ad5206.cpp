#include "Ad5206.h"

Ad5206::Ad5206(byte slaveSelectPin) {

  //Set the chip select pin to output and pull it high (disable)
  _slaveSelectPin = slaveSelectPin;
  pinMode(_slaveSelectPin, OUTPUT);
  digitalWrite(_slaveSelectPin, HIGH);
  
  //Start SPI
  SPI.begin();
}

void Ad5206::write(byte address, byte value) {
  // take the SS pin low to select the chip:
  digitalWrite(_slaveSelectPin,LOW);
  //  send in the address and value via SPI:
  SPI.transfer(address);
  SPI.transfer(value);
  // take the SS pin high to de-select the chip:
  digitalWrite(_slaveSelectPin,HIGH); 
}

