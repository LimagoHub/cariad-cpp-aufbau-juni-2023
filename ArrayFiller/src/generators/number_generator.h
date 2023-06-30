//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once

#include <cstdint>
#include "generator.h"

namespace generators {
    class number_generator :public generator<std::int32_t>{
        public:
            auto next() -> std::int32_t override = 0;

    };
}
