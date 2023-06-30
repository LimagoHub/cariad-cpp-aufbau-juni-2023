//
// Created by JoachimWagner on 29.06.2023.
//

#pragma once
#include "gmock/gmock.h"
#include "Mockplayer.h"
#include "Mockwriter.h"
#include "MyAbstractGameDummy.h"

using namespace testing;

class abstract_game_test: public Test {

protected:
    Mockwriter writer_mock;
    NiceMock<Mockplayer> game_player_mock;
    MyAbstractGameDummy object_under_test{writer_mock};

    void SetUp() override {
        object_under_test.add_player(&game_player_mock);
        ON_CALL(game_player_mock, get_name()).WillByDefault(Return("Mockplayer"));
    }
};
