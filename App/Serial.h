#pragma once

#include <stdint.h>
#include <stdlib.h>

class SerialClass
{
public:
  void write(const uint8_t *data, size_t length);
  size_t read(uint8_t *data, size_t length);
};

extern SerialClass Serial;