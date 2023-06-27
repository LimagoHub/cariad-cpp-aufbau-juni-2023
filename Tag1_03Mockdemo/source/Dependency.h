//
// Created by JoachimWagner on 26.06.2023.
//

#pragma once


#include <string>

class Dependency {
public:
    virtual void foo(std::string message)  const = 0;
    virtual int bar() const = 0;
    virtual int foobar(std::string message) const = 0;

};
