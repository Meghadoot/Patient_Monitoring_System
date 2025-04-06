/************************************************

hal_uart.h

************************************************/

#ifndef HAL_UART_H
#define HAL_UART_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
    HAL_UART_OK = 0,
    HAL_UART_ERROR,
    HAL_UART_NOT_IMPLEMENTED
} HAL_Status;

typedef struct {
    int baud_rate;
    int data_bits;
    int stop_bits;
    int parity;      // 0 = None, 1 = Odd, 2 = Even
    int flow_control;
} HAL_UART_Config;

#ifdef __cplusplus
extern "C" {
#endif

HAL_Status HAL_UART_Init(int instance_id, HAL_UART_Config* config);
HAL_Status HAL_UART_Send(int instance_id, const uint8_t* data, size_t len);
HAL_Status HAL_UART_Receive(int instance_id, uint8_t* buffer, size_t buf_size, size_t* received_len);
void HAL_UART_Deinit(int instance_id);

#ifdef __cplusplus
}
#endif

#endif // HAL_UART_H
