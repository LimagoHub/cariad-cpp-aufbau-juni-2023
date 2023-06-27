//
// Created by JoachimWagner on 27.06.2023.
//

#pragma once
#include "gmock/gmock.h"
#include "../../source/services/personen_service_impl.h"
#include "../Mockpersonen_repository.h"

using namespace testing;

class personen_service_impl_test: public Test {

protected:
    Mockpersonen_repository repoMock;
    personen_service_impl objectUnderTest{repoMock};
};
