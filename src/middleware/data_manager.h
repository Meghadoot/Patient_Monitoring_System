/************************************************

 data_manager.h

************************************************/

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <stdbool.h>

#define DATA_BUFFER_SIZE 10
#define DATA_MAX_MSG_LEN 256

void DataManager_Init(void);
bool DataManager_PushMessage(const char *msg);
bool DataManager_PopMessage(char *buffer, int buffer_len);
bool DataManager_IsEmpty(void);
void DataManager_Cleanup(void);

#endif // DATA_MANAGER_H
