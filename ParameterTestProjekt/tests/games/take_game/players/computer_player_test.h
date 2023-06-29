//
// Created by JoachimWagner on 14.12.2022.
//

#pragma once
#include "gmock/gmock.h"
#include "MockWriter.h"
#include "../../../source/games/take_game/players/computer_player.h"

using namespace testing;

class computer_player_test : public Test{

protected:
    MockWriter writerMock;
    computer_player object_under_test{writerMock};

};







