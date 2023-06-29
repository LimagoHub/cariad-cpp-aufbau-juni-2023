//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include <iostream>
#include "../io/Writer.h"

class computer_player {
    /*
     * Äquivalentklasse
     *
     * 1 Menge der durch vier teilbaren zahlen
     * 2 Menge der durch vier teilbaren zahlen mit Rest 1
     * 3 Menge der durch vier teilbaren zahlen mit Rest 2
     * 4 Menge der durch vier teilbaren zahlen mit Rest 3
     */

    Writer &writer;
public:
    explicit computer_player(Writer &writer) : writer(writer) {}

    unsigned do_turn(const unsigned &stones) const  {

        const int moves[] = {3,1,1,2};
        int move = moves[stones % 4];
        writer.write("Computer nimmt " + std::to_string(move) + " Steine.");
        return move;
    }
};




