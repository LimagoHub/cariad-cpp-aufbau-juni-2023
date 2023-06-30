//
// Created by JoachimWagner on 29.06.2023.
//

#pragma once
#include "player.h"
template<class BOARD, class TURN>
class abstract_player: public player<BOARD,TURN> {

    std::string name;

public:
    explicit abstract_player(const std::string &name) : name(name) {}

    std::string get_name() const override {
        return name;
    }
};
