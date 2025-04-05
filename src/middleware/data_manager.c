/**************************************************

 data_manager.c

***************************************************/

#include "data_manager.h"
#include <string.h>
#include <stdio.h>

static char data_buffer[DATA_BUFFER_SIZE][DATA_MAX_MSG_LEN];
static int head = 0;
static int tail = 0;
static int count = 0;

void DataManager_Init(void) {
    head = tail = count = 0;
    memset(data_buffer, 0, sizeof(data_buffer));
}

bool DataManager_PushMessage(const char *msg) {
    if (count >= DATA_BUFFER_SIZE) {
        // Buffer full
        return false;
    }

    strncpy(data_buffer[head], msg, DATA_MAX_MSG_LEN - 1);
    data_buffer[head][DATA_MAX_MSG_LEN - 1] = '\0';
    head = (head + 1) % DATA_BUFFER_SIZE;
    count++;
    return true;
}

bool DataManager_PopMessage(char *buffer, int buffer_len) {
    if (count == 0) {
        // Buffer empty
        return false;
    }

    strncpy(buffer, data_buffer[tail], buffer_len - 1);
    buffer[buffer_len - 1] = '\0';
    tail = (tail + 1) % DATA_BUFFER_SIZE;
    count--;
    return true;
}

bool DataManager_IsEmpty(void) {
    return count == 0;
}

void DataManager_Cleanup(void) {
    head = tail = count = 0;
    memset(data_buffer, 0, sizeof(data_buffer));
}
