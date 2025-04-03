// HAL I2C Header File
#ifndef HAL_I2C_H
#define HAL_I2C_H

void HAL_I2C_Init(int bus);
void HAL_I2C_Write(int bus, int address, const uint8_t *data, int length);
void HAL_I2C_Read(int bus, int address, uint8_t *data, int length);

#endif // HAL_I2C_H
