#include "Timer.hpp"

void Timer::start()
{
    mBegin = std::chrono::steady_clock::now();
    mClockRunning = true;
    mUsed = true;
}

void Timer::finish()
{
    mEnd = std::chrono::steady_clock::now();
    mClockRunning = false;
}

double Timer::getInterval()
{
    if(!mUsed)
    {
        return 0.0;
    }
    
    if(mClockRunning)
    {
        return 0.0;
    }
    
    auto interval = std::chrono::duration_cast<std::chrono::milliseconds>(mEnd - mBegin);
    return interval.count();
}
