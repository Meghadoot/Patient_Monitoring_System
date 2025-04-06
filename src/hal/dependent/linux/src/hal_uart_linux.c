/************************************************

hal_uart_linux.c

************************************************/


#include "hal_uart_linux.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

HAL_Status HAL_UART_Linux_Init(int instance_id, HAL_UART_Config* config) {
    // Dummy placeholder
    printf("[Linux UART] Init called for instance %d with baud %d\n", instance_id, config->baud_rate);
    return HAL_UART_OK;
}

HAL_Status HAL_UART_Linux_Send(int instance_id, const uint8_t* data, size_t len) {
    // Dummy placeholder
    printf("[Linux UART] Sending %zu bytes: %.*s\n", len, (int)len, data);
    return HAL_UART_OK;
}

HAL_Status HAL_UART_Linux_Receive(int instance_id, uint8_t* buffer, size_t buf_size, size_t* received_len) {
    // Dummy placeholder
    const char* dummy = "RX Dummy Data\n";
    size_t dummy_len = strlen(dummy);

    if (dummy_len > buf_size) return HAL_UART_ERROR;

    memcpy(buffer, dummy, dummy_len);
    *received_len = dummy_len;

    printf("[Linux UART] Received %zu bytes\n", dummy_len);
    return HAL_UART_OK;
}

void HAL_UART_Linux_Deinit(int instance_id) {
    printf("[Linux UART] Deinit called for instance %d\n", instance_id);
}
