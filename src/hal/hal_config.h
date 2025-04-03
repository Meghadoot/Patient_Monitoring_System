// HAL Configuration Header File
#ifndef HAL_CONFIG_H
#define HAL_CONFIG_H

// Define default configurations
#define DEFAULT_I2C_BUS 1
#define DEFAULT_SPI_BUS 0
#define DEFAULT_PWM_FREQUENCY 1000
#define DEFAULT_PWM_DUTY_CYCLE 50

// Debug Macros
#define HAL_DEBUG 1
#if HAL_DEBUG
#include <stdio.h>
#define DEBUG_PRINT(fmt, args...) printf("[HAL DEBUG] " fmt "\n", ##args)
#else
#define DEBUG_PRINT(fmt, args...)
#endif

#endif // HAL_CONFIG_H
