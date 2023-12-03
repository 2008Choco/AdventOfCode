#include "pch.h"
#include "SimpleTimer.h"

namespace aoclib
{
    SimpleTimer::SimpleTimer()
        : _start(std::chrono::high_resolution_clock::now()) {}

    void SimpleTimer::reset()
    {
        _start = std::chrono::high_resolution_clock::now();
    }

    unsigned int SimpleTimer::getTimeMillis() const
    {
        using namespace std::chrono;

        auto now = high_resolution_clock::now();
        auto millis = duration_cast<milliseconds>(now - _start);
        return millis.count();
    }
}
