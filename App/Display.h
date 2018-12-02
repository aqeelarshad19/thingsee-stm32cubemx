#pragma once

#include <stdint.h>

class DisplayClass
{
public:
  static const int DisplayMemorySize = 128 * 64 / 8;

  enum AddressMode
  {
    Horizontal,
    Vertical,
    Page
  };

  void begin();

  void enable(bool status);
  void setAddressMode(AddressMode mode);
  void home();

  void clear();
  void drawPixel(uint8_t x, uint8_t y);

protected:
  void writeCommand(uint8_t command);
  void writeData(uint8_t data);

  void setDataPin(bool state);
  void setResetPin(bool state);
  void setChipSelectPin(bool state);

  void init();
};

extern DisplayClass Display;