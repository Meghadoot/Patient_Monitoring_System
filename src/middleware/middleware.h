/*******************************

 middleware.h

********************************/

#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include "ipc_handler.h"
#include "data_manager.h"

void Middleware_Init(void);
void Middleware_Run(void);
void Middleware_Cleanup(void);

#endif // MIDDLEWARE_H
