//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once

#include <chrono>
#include "stopwatch.h"

namespace times {

    class stopwatch_impl : public stopwatch {
    public:
        void start() {
            startTime_ = std::chrono::high_resolution_clock::now();
        }

        void stop() {
            endTime_ = std::chrono::high_resolution_clock::now();
        }

        std::chrono::milliseconds elapsedDuration() {
            return std::chrono::duration_cast<std::chrono::milliseconds>(endTime_ - startTime_);
        }


    private:
        std::chrono::high_resolution_clock::time_point  startTime_;
        std::chrono::high_resolution_clock::time_point  endTime_;
    };

}