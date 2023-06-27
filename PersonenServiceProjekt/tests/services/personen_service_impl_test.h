//
// Created by JoachimWagner on 27.06.2023.
//

#pragma once
#include "gmock/gmock.h"
#include "../../source/services/personen_service_impl.h"
#include "../Mockpersonen_repository.h"
#include "../Mockblacklist_service.h"

using namespace testing;

class personen_service_impl_test: public Test {

protected:
    NaggyMock<Mockpersonen_repository> repoMock;
    NiceMock<Mockblacklist_service> blacklistMock;
    personen_service_impl objectUnderTest{repoMock, blacklistMock};

    void SetUp() override;
};
