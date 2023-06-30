//
// Created by JoachimWagner on 29.06.2023.
//

#pragma once
#include "DummyClassesForTest.h"
#include "../../game/abstract_game.h"

class MyAbstractGameDummy :public abstract_game<DummyBoard,DummyMove>{


public:
    bool game_over{ false };
    bool move_valid{ true };
    MyAbstractGameDummy(Writer &writer) : abstract_game(writer) {}
protected:
    bool is_turn_valid() const override {
        return move_valid;
    }

    void updateBoard() override {
        // Ok (PAL)
    }

    bool is_game_over() const override {
        return game_over;
    }
};
