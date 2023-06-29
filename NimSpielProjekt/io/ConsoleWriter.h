//
// Created by JoachimWagner on 29.06.2023.
//

#pragma once

#include <iostream>
#include "Writer.h"

class ConsoleWriter: public Writer {
public:
    void write(const std::string &message) const override {
        std::cout << message << std::endl;
    }
};
