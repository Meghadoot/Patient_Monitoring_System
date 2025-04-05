/*************************************

 middleware_config.h

**************************************/
#ifndef MIDDLEWARE_CONFIG_H
#define MIDDLEWARE_CONFIG_H

// Enable debug logging for middleware
#define MIDDLEWARE_DEBUG 1

// Max length of internal messages
#define MIDDLEWARE_MAX_MSG_LEN 256

// Define D-Bus details
#define MW_DBUS_SERVICE       "com.patient.monitoring"
#define MW_DBUS_INTERFACE     "com.patient.monitoring.Interface"
#define MW_DBUS_OBJECT_PATH   "/com/patient/monitoring"

// Unix Domain Socket path
#define MW_UDS_PATH "/tmp/middleware_socket"

#endif // MIDDLEWARE_CONFIG_H
