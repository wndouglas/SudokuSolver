#ifndef TIMER_H
#define TIMER_H

#include <chrono>

namespace SSLib
{
    class Timer
    {
    public:
        typedef double seconds;
        Timer() : mClockRunning(false), mUsed(false) { }
        void start();
        void finish();
        seconds getInterval();
        
    private:
        std::chrono::steady_clock::time_point mBegin;
        std::chrono::steady_clock::time_point mEnd;
        std::chrono::nanoseconds mInterval;
        bool mClockRunning;
        bool mUsed;
    };
}

#endif /* Timer_h */
