#include "Display.h"

#include "main.h"
#include "stm32l1xx_hal.h"

DisplayClass Display;

extern "C" SPI_HandleTypeDef hspi2;

uint8_t u8x8GPIOAndDelayThingsee(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  switch (msg)
  {
  case U8X8_MSG_GPIO_AND_DELAY_INIT: // called once during init phase of u8g2/u8x8
    break;                           // can be used to setup pins
  case U8X8_MSG_DELAY_NANO:          // delay arg_int * 1 nano second
  {
    int i;
    for (i = 0; i < arg_int / 2; i++)
      ;
  }
  break;
  case U8X8_MSG_DELAY_100NANO: // delay arg_int * 100 nano seconds
  {
    int i;
    for (i = 0; i < arg_int * 5; i++)
      ;
  }
  break;
  case U8X8_MSG_DELAY_10MICRO: // delay arg_int * 10 micro seconds
  {
    int i;
    for (i = 0; i < arg_int * 500; i++)
      ;
  }
  break;
  case U8X8_MSG_DELAY_MILLI: // delay arg_int * 1 milli second
    HAL_Delay(arg_int);
    break;
  case U8X8_MSG_GPIO_CS: // CS (chip select) pin: Output level in arg_int
    HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, (GPIO_PinState)arg_int);
    break;
  case U8X8_MSG_GPIO_DC: // DC (data/cmd, A0, register select) pin: Output level in arg_int
    HAL_GPIO_WritePin(DISPLAY_CMDDATA_GPIO_Port, DISPLAY_CMDDATA_Pin, (GPIO_PinState)arg_int);
    break;
  case U8X8_MSG_GPIO_RESET: // Reset pin: Output level in arg_int
    HAL_GPIO_WritePin(DISPLAY_RESET_GPIO_Port, DISPLAY_RESET_Pin, (GPIO_PinState)arg_int);
    break;
  case U8X8_MSG_GPIO_MENU_SELECT:
    u8x8_SetGPIOResult(u8x8, /* get menu select pin state */ 0);
    break;
  case U8X8_MSG_GPIO_MENU_NEXT:
    u8x8_SetGPIOResult(u8x8, /* get menu next pin state */ 0);
    break;
  case U8X8_MSG_GPIO_MENU_PREV:
    u8x8_SetGPIOResult(u8x8, /* get menu prev pin state */ 0);
    break;
  case U8X8_MSG_GPIO_MENU_HOME:
    u8x8_SetGPIOResult(u8x8, /* get menu home pin state */ 0);
    break;
  default:
    u8x8_SetGPIOResult(u8x8, 1); // default return value
    break;
  }
  return 1;
}

uint8_t u8x8ByteHardwareSPI(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  uint8_t *data;
  switch (msg)
  {
  case U8X8_MSG_BYTE_SEND:
    data = (uint8_t *)arg_ptr;
    while (arg_int > 0)
    {
      HAL_SPI_Transmit(&hspi2, (uint8_t *)data, 1, 5);
      data++;
      arg_int--;
    }
    break;
    break;
  case U8X8_MSG_BYTE_SET_DC:
    u8x8_gpio_SetDC(u8x8, arg_int);
    break;
  case U8X8_MSG_BYTE_START_TRANSFER:
    u8x8_gpio_SetCS(u8x8, u8x8->display_info->chip_enable_level);
    u8x8->gpio_and_delay_cb(u8x8, U8X8_MSG_DELAY_NANO, u8x8->display_info->post_chip_enable_wait_ns, NULL);
    break;
  case U8X8_MSG_BYTE_END_TRANSFER:
    u8x8->gpio_and_delay_cb(u8x8, U8X8_MSG_DELAY_NANO, u8x8->display_info->pre_chip_disable_wait_ns, NULL);
    u8x8_gpio_SetCS(u8x8, u8x8->display_info->chip_disable_level);
    break;
  default:
    return 0;
  }
  return 1;
}

void DisplayClass::start()
{
  setPowerPin(true);
  HAL_SPI_Init(&hspi2);
  u8x8_Setup(&u8x8_, u8x8_d_ssd1306_128x64_noname, u8x8_cad_001, u8x8ByteHardwareSPI, u8x8GPIOAndDelayThingsee);
  u8x8_InitDisplay(&u8x8_);
  u8x8_ClearDisplay(&u8x8_);
  u8x8_SetPowerSave(&u8x8_, 0);
  u8x8_SetFont(&u8x8_, u8x8_font_chroma48medium8_r);
  u8x8_DrawString(&u8x8_, 0, 0, "Hello World!");
}

void DisplayClass::stop()
{
  setPowerPin(false);
  HAL_SPI_DeInit(&hspi2);
}

void DisplayClass::setPowerPin(bool state)
{
  HAL_GPIO_WritePin(DISPLAY_REGULATOR_GPIO_Port, DISPLAY_REGULATOR_Pin, (GPIO_PinState)state);
}
