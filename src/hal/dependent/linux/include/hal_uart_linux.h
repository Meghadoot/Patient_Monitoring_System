/************************************************

hal_uart_linux.h

************************************************/

#ifndef HAL_UART_LINUX_H
#define HAL_UART_LINUX_H

#include "hal_uart.h"

HAL_Status HAL_UART_Linux_Init(int instance_id, HAL_UART_Config* config);
HAL_Status HAL_UART_Linux_Send(int instance_id, const uint8_t* data, size_t len);
HAL_Status HAL_UART_Linux_Receive(int instance_id, uint8_t* buffer, size_t buf_size, size_t* received_len);
void HAL_UART_Linux_Deinit(int instance_id);

#endif // HAL_UART_LINUX_H
