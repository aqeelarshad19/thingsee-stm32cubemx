#include "Serial.h"

#include "usbd_cdc_if.h"

SerialClass Serial;

void SerialClass::write(const uint8_t *data, size_t length)
{
  CDC_Transmit_FS((uint8_t *)data, length);
}

size_t SerialClass::read(uint8_t *data, size_t length)
{
}