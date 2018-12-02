#pragma once

#include <stdint.h>

#include "u8x8.h"

class DisplayClass
{
public:
  static constexpr int DisplayMemorySize = 128 * 64 / 8;

  enum AddressMode
  {
    Horizontal,
    Vertical,
    Page
  };

  void start();
  void stop();

protected:
  void setPowerPin(bool state);

private:
  u8x8_t u8x8_;
};

extern DisplayClass Display;