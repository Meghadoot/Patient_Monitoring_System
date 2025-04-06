/******************************************

hal_common.h

*******************************************/


#ifndef HAL_COMMON_H
#define HAL_COMMON_H

#include <stdint.h>
#include <stddef.h>

// Return status
typedef enum {
    HAL_OK = 0,
    HAL_ERROR = -1,
    HAL_TIMEOUT = -2,
    HAL_NOT_IMPLEMENTED = -3
} HAL_Status;

// Generic initialization structure
typedef struct {
    int instance_id;
    void* config;
} HAL_InitTypeDef;

// Debugging utility
void HAL_Log(const char* module, const char* message);

#endif // HAL_COMMON_H
