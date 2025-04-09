/***********************************************************

NIBP Driver HAL :  Non-Invasive Blood Pressure 

Supported : Class A, B, C 

Utility : Wearables , IoMT, and Diagnostic MD 

************************************************************/



#ifndef NIBP_DRIVER_H
#define NIBP_DRIVER_H

#include <stdint.h>

typedef enum {
    NIBP_OK,
    NIBP_ERROR,
    NIBP_SENSOR_NOT_FOUND,
    NIBP_INVALID_READING
} NIBP_Status;

typedef struct {
    uint16_t systolic_mmHg;
    uint16_t diastolic_mmHg;
    uint16_t mean_arterial_pressure_mmHg;
    uint8_t pulse_rate_bpm;
} NIBP_Reading;

NIBP_Status NIBP_Driver_Init(int device_id);
NIBP_Status NIBP_Driver_Read(int device_id, NIBP_Reading* reading);
NIBP_Status NIBP_Driver_Shutdown(int device_id);

#endif // NIBP_DRIVER_H
