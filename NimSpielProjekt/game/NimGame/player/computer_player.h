//
// Created by JoachimWagner on 28.06.2023.
//

#pragma once

#include <iostream>
#include "abstract_nim_game_player.h"

class computer_player : public abstract_nim_game_player{
public:

    static inline const  int turns [] = {3,1,1,2};

    explicit computer_player(const std::string &name) : abstract_nim_game_player(name) {}

    int do_turn(const int &stones) const override {
        int turn;
        turn = turns[stones %4];
        std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
        return turn;
    }
};
