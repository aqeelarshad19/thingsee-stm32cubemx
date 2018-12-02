# thingsee-stm32cubemx

This repository constains a basic firmware for the Thingsee ONE, which is based on STM32CubeMX.
The high-level and board specific code is written in C++.
The project is using CMake for compilation, so please don't use the generated `Makefile` to build!

## Important Directories

The directories are organized like in normal STM32CubeMX project, so the following directories are those, which where added manually.

* **App**: Directory for the application code
* **Drivers/thingsee**: Sources for the peripheral drivers
* **Middlewares/u8g2**: Graphic/Display library for the OLED-Display