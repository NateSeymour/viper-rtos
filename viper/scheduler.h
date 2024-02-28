#ifndef VIPER_RTOS_SCHEDULER_H
#define VIPER_RTOS_SCHEDULER_H

#include <thread.h>
#include <std/int.h>
#include <std/vector.h>
#include <sys/control.h>
#include <std/mutex.h>

namespace viper
{

    class Scheduler
    {

    public:
    };

    extern Scheduler GlobalScheduler;
}

#endif //VIPER_RTOS_SCHEDULER_H
