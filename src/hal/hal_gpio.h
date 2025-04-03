// HAL GPIO Header File
#ifndef HAL_GPIO_H
#define HAL_GPIO_H

void HAL_GPIO_Init(int pin, int mode);
void HAL_GPIO_Write(int pin, int value);
int HAL_GPIO_Read(int pin);

#endif // HAL_GPIO_H
