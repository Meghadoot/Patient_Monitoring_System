// middleware.c - Middleware Core Source File
#include "middleware.h"
#include "ipc_handler.h"
#include "data_manager.h"
#include "middleware_config.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Initialize the middleware components.
 * This includes initializing the IPC layer and the data manager.
 */
void Middleware_Init() {
    DEBUG_LOG("Initializing Middleware...");
    IPC_Init();
    DataManager_Init();
}

/**
 * @brief Process messages received via IPC.
 * Handles both D-Bus and Unix Domain Socket inputs.
 */
void Middleware_Process() {
    DEBUG_LOG("Processing Middleware events...");
    IPC_HandleDBusMessages();
    IPC_ReceiveUDSMessages();
}

/**
 * @brief Route message to appropriate internal module or handler.
 * @param msg The message string received from IPC.
 */
void Middleware_RouteMessage(const char *msg) {
    if (msg == NULL || strlen(msg) == 0) {
        DEBUG_LOG("Received empty message, ignoring...");
        return;
    }
    DEBUG_LOG("Routing message to DataManager: %s", msg);
    DataManager_PushMessage(msg);
}
