#include "app.h"

#include "Display.h"
#include "Serial.h"

#include "main.h"
#include "stm32l1xx_hal.h"

#include <string.h>
#include <math.h>

const char text[] = "Hello World!\n";

extern "C" I2C_HandleTypeDef hi2c1;
extern "C" I2C_HandleTypeDef hi2c2;

void setup()
{
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);

    HAL_Delay(5000);

    HAL_I2C_Init(&hi2c1);
    HAL_I2C_Init(&hi2c2);

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

    uint8_t config[2] = {0x02, 0x40};
    HAL_I2C_Master_Transmit(&hi2c1, (0x4b << 1), config, 2, 2);
    HAL_Delay(1000);
    uint8_t reg[1] = {0x03};
    HAL_I2C_Master_Transmit(&hi2c1, (0x4b << 1), reg, 1, 2);
    uint8_t data[2];
    if (HAL_I2C_Master_Receive(&hi2c1, (0x4b << 1), data, 2, 2) == HAL_OK)
    {
        int exponent = (data[0] & 0xF0) >> 4;
        int mantissa = ((data[0] & 0x0F) << 4) | (data[1] & 0x0F);
        float luminance = pow(2, exponent) * mantissa * 0.045;

        // Output data to screen
        char buffer[100];
        snprintf(buffer, 100, "Ambient Light luminance : %.2f lux \n", luminance);
        Serial.write((const uint8_t *)buffer, strlen(buffer));
    }

    Display.begin();
    Display.clear();
}

void loop()
{
    Serial.write((const uint8_t *)text, strlen(text));
    HAL_Delay(1000);
}