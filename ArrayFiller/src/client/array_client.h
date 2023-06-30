//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once
#include <memory>
#include "../container/array_factory.h"

#define MAX_ARRAY_SIZE INT32_MAX/8

namespace client {
    template<class T>
    class array_client {

        collections::array_factory<T> &arrayFactory_;

    public:

        explicit array_client(collections::array_factory<T> &arrayFactory) : arrayFactory_(arrayFactory) {}

        auto go() -> void {
            // Do something with large array
           std::shared_ptr<T[]> data = arrayFactory_.create_and_fill_array(MAX_ARRAY_SIZE);
           std::cout << "erstes Element" << data[0] << std::endl;
        }

    };
}
