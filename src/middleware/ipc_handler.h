// ipc_handler.h - IPC Handler Header File
#ifndef IPC_HANDLER_H
#define IPC_HANDLER_H

#include <dbus/dbus.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define UDS_PATH "/var/run/middleware_socket" // to maintain across sessions/usrs
#define DBUS_SERVICE "com.MediTUX.Middleware" // Service registration name for MediTUX Middleware
#define DBUS_INTERFACE "com.MediTUX.Middleware.IPC" //interface under which D-Bus methods are exposed
#define DBUS_OBJECT_PATH "/com/MediTUX/Middleware" //path used inside D-Bus to refer middleware instance

void IPC_Init();
void IPC_HandleDBusMessages();
void IPC_SendUDSMessage(const char *message);
void IPC_ReceiveUDSMessages();
void IPC_Cleanup();

#endif // IPC_HANDLER_H
