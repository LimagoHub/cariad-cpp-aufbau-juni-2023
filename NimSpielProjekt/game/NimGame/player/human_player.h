//
// Created by JoachimWagner on 28.06.2023.
//

#pragma once

#include <iostream>
#include "abstract_nim_game_player.h"

class human_player: public abstract_nim_game_player {
public:
    explicit human_player(const std::string &name) : abstract_nim_game_player(name) {}

    int do_turn(const int &stones) const override {
        int turn;
        std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1, 2 oder 3." << std::endl;
        std::cin >> turn;
        return turn;
    }
};
