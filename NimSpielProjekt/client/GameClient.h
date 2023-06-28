//
// Created by JoachimWagner on 28.06.2023.
//

#pragma once


#include "../game/game.h"

class GameClient {

    game &game_;
public:
    explicit GameClient(game &game) : game_(game) {}

    void go() {
        game_.play();
    }

};
