//
// Created by JoachimWagner on 26.06.2023.
//

#include <iostream>
#include "DependencyImpl.h"

void DependencyImpl::foo(std::string message) const {
    std::cout << message << std::endl;
}

int DependencyImpl::bar() const {
    return 42;
}

int DependencyImpl::foobar(std::string message) const {
    return message.length();
}
