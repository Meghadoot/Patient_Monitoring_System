// ipc_handler.c - IPC Handler Source File
#include "ipc_handler.h"

static int uds_socket_fd = -1;
static DBusConnection *dbus_conn = NULL;

// Initialize IPC components (D-Bus & UDS)
void IPC_Init() {
    // Initialize D-Bus Connection
    DBusError err;
    dbus_error_init(&err);
    dbus_conn = dbus_bus_get(DBUS_BUS_SESSION, &err);
    if (dbus_error_is_set(&err)) {
        fprintf(stderr, "D-Bus Connection Error: %s\n", err.message);
        dbus_error_free(&err);
        return;
    }
    dbus_bus_request_name(dbus_conn, DBUS_SERVICE, DBUS_NAME_FLAG_REPLACE_EXISTING, &err);
    if (dbus_error_is_set(&err)) {
        fprintf(stderr, "D-Bus Name Request Error: %s\n", err.message);
        dbus_error_free(&err);
    }

    // Initialize Unix Domain Socket (UDS)
    struct sockaddr_un addr;
    uds_socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (uds_socket_fd < 0) {
        perror("UDS Socket Creation Failed");
        return;
    }
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, UDS_PATH, sizeof(addr.sun_path) - 1);
    unlink(UDS_PATH);
    if (bind(uds_socket_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("UDS Bind Failed");
        close(uds_socket_fd);
        return;
    }
}

// Handle incoming D-Bus messages
void IPC_HandleDBusMessages() {
    while (dbus_connection_read_write(dbus_conn, 0)) {
        DBusMessage *msg = dbus_connection_pop_message(dbus_conn);
        if (msg) {
            if (dbus_message_is_method_call(msg, DBUS_INTERFACE, "SendMessage")) {
                const char *message;
                if (dbus_message_get_args(msg, NULL, DBUS_TYPE_STRING, &message, DBUS_TYPE_INVALID)) {
                    printf("Received D-Bus Message: %s\n", message);
                }
            }
            dbus_message_unref(msg);
        }
    }
}

// Send a message via Unix Domain Socket
void IPC_SendUDSMessage(const char *message) {
    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, UDS_PATH, sizeof(addr.sun_path) - 1);
    if (sendto(uds_socket_fd, message, strlen(message), 0, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("UDS Send Failed");
    }
}

// Receive messages from Unix Domain Socket
void IPC_ReceiveUDSMessages() {
    char buffer[256];
    struct sockaddr_un addr;
    socklen_t addr_len = sizeof(addr);
    int len = recvfrom(uds_socket_fd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&addr, &addr_len);
    if (len > 0) {
        buffer[len] = '\0';
        printf("Received UDS Message: %s\n", buffer);
    }
}

// Cleanup IPC resources
void IPC_Cleanup() {
    if (dbus_conn) {
        dbus_connection_unref(dbus_conn);
    }
    if (uds_socket_fd >= 0) {
        close(uds_socket_fd);
        unlink(UDS_PATH);
    }
}
