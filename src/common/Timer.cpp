#include "Timer.hpp"

using namespace SSLib;

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

Timer::seconds Timer::getInterval()
{
    if(!mUsed)
    {
        return 0.0;
    }
    
    if(mClockRunning)
    {
        return 0.0;
    }
    
    auto interval = std::chrono::duration_cast<std::chrono::nanoseconds>(mEnd - mBegin);
    return interval.count()/1000000000.0;
}
