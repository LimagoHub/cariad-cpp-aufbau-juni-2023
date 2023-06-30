//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once
#include "../array_factory.h"
#include "../../generators/generator.h"
using namespace generators;

namespace collections {
    template<class T>
    class array_factory_sequencial_impl : public array_factory<T> {

        generator<T> &generator_;
    public:
        explicit array_factory_sequencial_impl(generator <T> &generator) : generator_(generator) {}

    public:
            auto create_and_fill_array(size_t size) -> std::shared_ptr<T[]> override {
                auto result = std::shared_ptr<int[]>{new int[size]};
                for(int i = 0; i < size; ++ i)
                {
                    result[i] = generator_.next();
                }
                return result;
            }
        };
}
