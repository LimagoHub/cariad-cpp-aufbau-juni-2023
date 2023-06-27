//
// Created by JoachimWagner on 26.06.2023.
//

#pragma once


#include "Dependency.h"
#include <algorithm>

class MyServiceUsingDependency {

    Dependency &dependency;

public:
    explicit MyServiceUsingDependency(Dependency &dependency) : dependency(dependency) {}

    void abc(std::string myMessage) {
        transform(myMessage.begin(), myMessage.end(), myMessage.begin(), ::toupper);
        dependency.foo(myMessage);
    }

    int bcd() {

        return dependency.bar() * dependency.bar() + 5;
    }

};
