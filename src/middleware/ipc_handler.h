/*******************************************

 ipc_handler.h - IPC Handler Header File

********************************************/

#ifndef IPC_HANDLER_H
#define IPC_HANDLER_H

void IPC_Init(void);
void IPC_HandleDBusMessages(void);
void IPC_SendUDSMessage(const char *message);
void IPC_ReceiveUDSMessages(void);
void IPC_Cleanup(void);

#endif // IPC_HANDLER_H

