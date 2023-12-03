#pragma once

#include <chrono>
#include <ostream>

namespace aoclib
{
    /**
     * A simple class that will store a high resolution time point at the time
     * of construction that can be retrieved or printed at a later time. Useful
     * for very precise but quick time measurements (faux-benchmarking).
     *
     * This class can be printed to an ostream which will append the current
     * time in milliseconds suffixed with "ms", e.g. "103ms".
     */
    class SimpleTimer
    {
    public:
        SimpleTimer();

        /**
         * Reset the timer's starting time point to now.
         */
        void reset();

        /**
         * Get the time (in milliseconds) between the timer's start point and now.
         *
         * @return the time elapsed in millis
         */
        long long getTimeMillis() const;

        friend std::ostream& operator<<(std::ostream& out, const SimpleTimer timer)
        {
            out << timer.getTimeMillis() << "ms";
            return out;
        }

    private:
        std::chrono::high_resolution_clock::time_point _start;
    };
}
