#ifndef TIMER_H
#define TIMER_H

#include <chrono>

// Timer allow recording of events in milliseconds
class Timer
{
public:
    Timer() : mClockRunning(false), mUsed(false) { }
    void start();
    void finish();
    double getInterval();
    
private:
    std::chrono::steady_clock::time_point mBegin;
    std::chrono::steady_clock::time_point mEnd;
    std::chrono::milliseconds mInterval;
    bool mClockRunning;
    bool mUsed;
};

#endif /* Timer_h */
