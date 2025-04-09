/****************************************************

Temperature Driver - Temp sensor for human body

****************************************************/


#ifndef TEMP_DRIVER_H
#define TEMP_DRIVER_H

#include <stdint.h>

typedef enum {
    TEMP_OK,
    TEMP_ERROR,
    TEMP_SENSOR_DISCONNECTED
} TEMP_Status;


typedef enum {
    TEMP_CELSIUS,
    TEMP_FAHRENHEIT,
    TEMP_KELVIN
} TEMP_Unit;

typedef struct {
    float temperature_value;
} TEMP_Reading;

TEMP_Status TEMP_Driver_Init(int device_id);
TEMP_Status TEMP_Driver_Read(int device_id, TEMP_Reading* reading, TEMP_Unit unit);
TEMP_Status TEMP_Driver_Shutdown(int device_id);

#endif // TEMP_DRIVER_H
