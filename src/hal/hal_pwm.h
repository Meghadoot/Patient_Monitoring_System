// HAL PWM Header File
#ifndef HAL_PWM_H
#define HAL_PWM_H

void HAL_PWM_Init(int channel, int frequency, int dutyCycle);
void HAL_PWM_Start(int channel);
void HAL_PWM_Stop(int channel);

#endif // HAL_PWM_H
