#include "app.h"

#include "main.h"
#include "stm32l1xx_hal.h"

#include "usbd_cdc_if.h"

#include <string.h>

const char text[] = "Hello World!\n";

void setup()
{
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
}

void loop()
{
    CDC_Transmit_FS((uint8_t *)text, strlen(text));
    HAL_Delay(1000);
}