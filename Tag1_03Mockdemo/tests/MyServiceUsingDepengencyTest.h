//
// Created by JoachimWagner on 26.06.2023.
//

#pragma once
#include "gmock/gmock.h"
#include "../source/MyServiceUsingDependency.h"
#include "MockDependency.h"
using namespace testing;
class MyServiceUsingDepengencyTest :public Test{

protected:
    MockDependency dependencyMock;
    MyServiceUsingDependency objectUnderTest{dependencyMock};
};
