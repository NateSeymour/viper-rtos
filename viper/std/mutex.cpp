#include <viper.h>
#include <std/mutex.h>
#include <handler.h>

__STDCALL bool std_mutex_acquire(std::Mutex *self);
__STDCALL bool std_mutex_release(std::Mutex *self);

bool std::Mutex::Lock(std::uint32_t max_attempt)
{
    uint32_t attempt_count = 0;

    while(true) {
        if(max_attempt > 0 && attempt_count >= max_attempt) {
            return false;
        }

        bool success = std_mutex_acquire(this);
        attempt_count++;

        if(!success) {
            viper::yield();
            continue;
        }

        return true;
    }
}

bool std::Mutex::TryLock()
{
    return std_mutex_acquire(this);
}

void std::Mutex::Release()
{
    std_mutex_release(this);
}

std::Mutex::~Mutex()
{
    this->Release();
}
