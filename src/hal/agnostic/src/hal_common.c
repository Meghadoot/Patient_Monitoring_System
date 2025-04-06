/*****************************************

hal_common.c

******************************************/


#include "hal_common.h"
#include <stdio.h>
#include <time.h>

void HAL_Log(const char* module, const char* message) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    printf("[%02d:%02d:%02d] [%s]: %s\n",
           t->tm_hour, t->tm_min, t->tm_sec,
           module, message);
}
