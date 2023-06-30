//
// Created by JoachimWagner on 28.06.2023.
//

#pragma once


#include "../../player/abstract_game_player.h"

class abstract_nim_game_player: public abstract_player<int, int> {



public:
    explicit abstract_nim_game_player(const std::string &name) : abstract_player<int, int>(name) {}

    std::string get_name() const override {
        return abstract_player::get_name();
    }
};
