/****************************************************

Accelerometer Driver - For movement, orientation, and fall detection

****************************************************/

#ifndef ACCEL_DRIVER_H
#define ACCEL_DRIVER_H

#include <stdint.h>
#include <time.h>

typedef enum {
    ACCEL_OK,
    ACCEL_ERROR,
    ACCEL_SENSOR_DISCONNECTED
} ACCEL_Status;

typedef enum {
    ACCEL_UNIT_M_S2,       // Meters per second squared
    ACCEL_UNIT_G_FORCE     // g-force
} ACCEL_Unit;

typedef struct {
    float x_axis;
    float y_axis;
    float z_axis;
    ACCEL_Unit unit_value;
    struct tm timestamp_value;  // Contains fields like tm_hour, tm_min, tm_sec
} ACCEL_Reading;

ACCEL_Status ACCEL_Driver_Init(int device_id);
ACCEL_Status ACCEL_Driver_Read(int device_id, ACCEL_Reading* reading);
ACCEL_Status ACCEL_Driver_Shutdown(int device_id);

#endif // ACCEL_DRIVER_H
