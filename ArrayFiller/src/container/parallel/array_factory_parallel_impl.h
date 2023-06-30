//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once

#include <vector>
#include <thread>
#include <cmath>
#include "../array_factory.h"
#include "../../generators/number_generator_factory.h"
using namespace generators;

namespace collections {

    template<class T>
    class array_factory_parallel_impl : public array_factory<T> {

        number_generator_factory &generatorFactory_;
        size_t thread_count_;
        std::vector<std::thread> threadHolder_;
        std::size_t partitionSize_;


    public:
        array_factory_parallel_impl(number_generator_factory  &generatorFactory, size_t threadCount) : generatorFactory_(
                generatorFactory),
                thread_count_(threadCount) {}

        auto create_and_fill_array(size_t size) -> std::shared_ptr<T[]> override {
            std::shared_ptr<T[]> result(new T[size]);
            calculatePartitionSize(size);
            initializeThreadHolder();
            addWorkersToThreads(result);
            joinThreads();
            return result;
        }

    private:
        auto calculatePartitionSize(size_t size) -> void {
            partitionSize_ = static_cast<std::size_t>(std::floor(size / thread_count_));
        }

        auto initializeThreadHolder()  -> void
        {
            threadHolder_ = std::vector<std::thread>{};
            threadHolder_.reserve(thread_count_);
        }

        auto addWorkersToThreads(std::shared_ptr<T[]> result)  -> void
        {
            for (auto segment = 0U; segment < thread_count_; ++segment) {
                start_single_worker_for_segment(result, segment);
            }
        }

        auto joinThreads() -> void
        {
            for (auto& thread : threadHolder_) {
                thread.join();
            }
        }

        auto  start_single_worker_for_segment(std::shared_ptr<T[]> result, const unsigned int segment) -> void
        {
            threadHolder_.emplace_back(
                    [this, result](auto const startIndex, auto const endIndex) {
                        this->fill_segment_worker(result, startIndex, endIndex);
                    },
                    segment * partitionSize_, (segment + 1) * partitionSize_);
        }

        auto fill_segment_worker(std::shared_ptr<T[]> result, std::size_t startIndex, std::size_t endIndex) -> void
        {
            auto const numberGenerator = generatorFactory_.create();

            for (auto i = startIndex; i < endIndex; ++i) {
                result[i] = numberGenerator->next();

            }
        }

    };
}