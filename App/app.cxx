#include "app.h"

#include "Display.h"
#include "Serial.h"
#include "Luxmeter.h"

#include "main.h"
#include "stm32l1xx_hal.h"

#include <string.h>

const char text[] = "Hello World!\n";

extern "C" I2C_HandleTypeDef hi2c1;
extern "C" I2C_HandleTypeDef hi2c2;

void setup()
{
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);

    Display.start();

    HAL_Delay(5000);

    HAL_I2C_Init(&hi2c1);

    Luxmeter.start();

    // for (uint16_t address = 1; address < 128; address++)
    // {
    //     if (HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(address << 1), 2, 2) == HAL_OK)
    //     {
    //         char buffer[100];
    //         snprintf(buffer, 100, "Found device on I2C1: 0x%02x\n", address);
    //         Serial.write((const uint8_t *)buffer, strlen(buffer));
    //     }
    //     if (HAL_I2C_IsDeviceReady(&hi2c2, (uint16_t)(address << 1), 2, 2) == HAL_OK)
    //     {
    //         char buffer[100];
    //         snprintf(buffer, 100, "Found device on I2C2: 0x%02x\n", address);
    //         Serial.write((const uint8_t *)buffer, strlen(buffer));
    //     }
    //     HAL_Delay(50);
    // }
    char buffer[100];
    snprintf(buffer, 100, "Lux: %.2f\n", Luxmeter.readLux());
    Serial.write((const uint8_t *)buffer, strlen(buffer));
}

void loop()
{
    Serial.write((const uint8_t *)text, strlen(text));
    HAL_Delay(1000);
}