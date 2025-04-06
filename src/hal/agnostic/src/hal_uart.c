
/************************************************

hal_uart.c

************************************************/


#include "hal_uart.h"
#include "hal_common.h"

// Platform-specific backend
#ifdef PLATFORM_LINUX
#include "../../dependent/linux/include/hal_uart_linux.h"
#endif

HAL_Status HAL_UART_Init(int instance_id, HAL_UART_Config* config) {
    HAL_Log("UART", "Initializing UART");

#ifdef PLATFORM_LINUX
    return HAL_UART_Linux_Init(instance_id, config);
#else
    return HAL_UART_NOT_IMPLEMENTED;
#endif
}

HAL_Status HAL_UART_Send(int instance_id, const uint8_t* data, size_t len) {
    HAL_Log("UART", "Sending data");

#ifdef PLATFORM_LINUX
    return HAL_UART_Linux_Send(instance_id, data, len);
#else
    return HAL_UART_NOT_IMPLEMENTED;
#endif
}

HAL_Status HAL_UART_Receive(int instance_id, uint8_t* buffer, size_t buf_size, size_t* received_len) {
    HAL_Log("UART", "Receiving data");

#ifdef PLATFORM_LINUX
    return HAL_UART_Linux_Receive(instance_id, buffer, buf_size, received_len);
#else
    return HAL_UART_NOT_IMPLEMENTED;
#endif
}

void HAL_UART_Deinit(int instance_id) {
    HAL_Log("UART", "Deinitializing UART");

#ifdef PLATFORM_LINUX
    HAL_UART_Linux_Deinit(instance_id);
#endif
}

