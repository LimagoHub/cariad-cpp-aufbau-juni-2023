//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once
#include <memory>
#include "mersenne_twister_number_generator.h"
#include "../number_generator_factory.h"

namespace generators {
    class mersenne_twister_number_generator_factory : public number_generator_factory {
    public:
        [[nodiscard]] auto create() const -> std::unique_ptr<number_generator> override
        {
            return std::make_unique<mersenne_twister_number_generator>();
        }
    };
}
