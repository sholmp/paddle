#include "stopwatch.h"


void StopWatch::start()
{
    running_ = true;
}

void StopWatch::pause()
{
    running_ = false;
    elapsed_time_ = elapsed_time_ + (std::chrono::system_clock::now() - start_time_);
}

void StopWatch::reset()
{
//    elapsed_time_ =
}

StopWatch::duration StopWatch::elapsedTime()
{
    return elapsed_time_ + (std::chrono::system_clock::now() - start_time_);
}

bool StopWatch::isRunning()
{
    return running_;
}
