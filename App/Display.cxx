#include "Display.h"

#include "main.h"
#include "stm32l1xx_hal.h"

DisplayClass Display;

extern "C" SPI_HandleTypeDef hspi2;

void DisplayClass::begin()
{
  HAL_GPIO_WritePin(DISPLAY_REGULATOR_GPIO_Port, DISPLAY_REGULATOR_Pin, GPIO_PIN_SET);
  HAL_Delay(500);
  HAL_SPI_Init(&hspi2);
  init();
}

void DisplayClass::writeCommand(uint8_t command)
{
  setDataPin(false);
  setChipSelectPin(false);
  HAL_Delay(1);
  HAL_SPI_Transmit(&hspi2, &command, 1, 5);
  HAL_Delay(1);
  setChipSelectPin(true);
}

void DisplayClass::writeData(uint8_t data)
{
  setDataPin(true);
  setChipSelectPin(false);
  HAL_Delay(1);
  HAL_SPI_Transmit(&hspi2, &data, 1, 5);
  HAL_Delay(1);
  setChipSelectPin(true);
}

void DisplayClass::setDataPin(bool state)
{
  HAL_GPIO_WritePin(DISPLAY_CMDDATA_GPIO_Port, DISPLAY_CMDDATA_Pin, (GPIO_PinState)state);
}

void DisplayClass::setResetPin(bool state)
{
  HAL_GPIO_WritePin(DISPLAY_RESET_GPIO_Port, DISPLAY_RESET_Pin, (GPIO_PinState)state);
}

void DisplayClass::setChipSelectPin(bool state)
{
  HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, (GPIO_PinState)state);
}

void DisplayClass::init()
{
  setResetPin(false);
  HAL_Delay(10);
  setResetPin(true);
  HAL_Delay(10);

  writeCommand(0xAE); // display off

  HAL_Delay(20);

  writeCommand(0xD5); // clock
  HAL_Delay(20);
  writeCommand(0x81); // upper nibble is rate, lower nibble is divisor
  HAL_Delay(20);

  writeCommand(0xA8); // mux ratio
  HAL_Delay(20);
  writeCommand(0x3F); // rtfm
  HAL_Delay(20);

  writeCommand(0xD3); // display offset
  HAL_Delay(20);
  writeCommand(0x00); // rtfm
  HAL_Delay(20);
  writeCommand(0x00);

  HAL_Delay(20);
  writeCommand(0x8D); // charge pump
  HAL_Delay(20);
  writeCommand(0x14); // enable
  HAL_Delay(20);

  writeCommand(0x20); // memory addr mode
  HAL_Delay(20);
  writeCommand(0x00); // horizontal
  HAL_Delay(20);

  writeCommand(0xA1); // segment remap
  HAL_Delay(20);

  writeCommand(0xA5); // display on
  HAL_Delay(20);

  writeCommand(0xC8); // com scan direction
  HAL_Delay(20);
  writeCommand(0xDA); // com hardware cfg
  HAL_Delay(20);
  writeCommand(0x12); // alt com cfg
  HAL_Delay(20);

  writeCommand(0x81); // contrast aka current
  HAL_Delay(20);
  writeCommand(0x7F); // 128 is midpoint
  HAL_Delay(20);

  writeCommand(0xD9); // precharge
  HAL_Delay(20);
  writeCommand(0x11); // rtfm
  HAL_Delay(20);

  writeCommand(0xDB); // vcomh deselect level
  HAL_Delay(20);
  writeCommand(0x20); // rtfm
  HAL_Delay(20);

  writeCommand(0xA6); // non-inverted
  HAL_Delay(20);

  writeCommand(0xA4); // display scan on
  HAL_Delay(20);
  writeCommand(0xAF); // drivers on
  HAL_Delay(20);
}

void DisplayClass::setAddressMode(AddressMode mode)
{
  writeCommand(0x20);
  writeCommand((mode < 2) ? mode : 0);
}

void DisplayClass::home()
{
  writeCommand(0x21); // column range
  writeCommand(0x00); //  set start to 0
  writeCommand(0x7F); //  set end to 0x7F
  writeCommand(0x22); // row range
  writeCommand(0x00); //  set start to 0
  writeCommand(0x07); //  set end to 0x07
}

void DisplayClass::enable(bool status)
{
}

void DisplayClass::clear()
{
  home();
  for (uint16_t i = DisplayMemorySize; i > 0; i--)
  {
    writeData(0x55);
  }
}

void DisplayClass::drawPixel(uint8_t x, uint8_t y)
{
}
