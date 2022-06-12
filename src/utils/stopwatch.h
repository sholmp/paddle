#pragma once

#include <chrono>

class StopWatch
{
    using timepoint = std::chrono::time_point<std::chrono::system_clock>;
    using duration = std::chrono::duration<long, std::ratio<1, 1000000000>>;
    
     void start();
     void pause();
     void reset();
    
     duration elapsedTime();
     bool isRunning();
    
private:
    timepoint start_time_;
    duration elapsed_time_;
    bool running_{false};  
};
