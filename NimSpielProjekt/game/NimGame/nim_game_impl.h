//
// Created by JoachimWagner on 28.06.2023.
//

#pragma once
#include "../game.h"
#include "../../io/Writer.h"
#include "../abstract_game.h"
#include <vector>

class nim_game_impl : public abstract_game<int,int>{

public:
    explicit nim_game_impl(Writer &writer) : abstract_game<int, int>(writer) {
        setBoard(23);
    }


protected:
    // Im Sumpf
    bool is_turn_valid() const override{ // Operation
        return getTurn() >= 1 && getTurn() <= 3;
    }

    void updateBoard() { setBoard(getBoard() - getTurn()); }

    bool is_game_over() const override{
        return getBoard() < 1 || getPlayers().empty();
    }

};
