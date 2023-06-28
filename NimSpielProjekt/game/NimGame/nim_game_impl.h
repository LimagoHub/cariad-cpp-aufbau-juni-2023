//
// Created by JoachimWagner on 28.06.2023.
//

#pragma once


#include <iostream>
#include "../game.h"

class nim_game_impl : public game{
   int stones;

public:
    nim_game_impl():stones(23), game_over(false) {}
    void play() override {
        while(! is_game_over()) {
            execute_round();
        }
    }
private:
    void execute_round() {
        spieler_zug();
        computer_zug();
    }

    void spieler_zug() {
        int turn;

        while(true) {
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1, 2 oder 3." << std::endl;
            std::cin >> turn;
            if(turn >= 1 && turn <= 3) break;
            std::cout << "Ungültiger Zug" << std::endl;
        }

        stones -= turn;
    }
    void computer_zug() {
        const  int turns [] = {3,1,1,2};
        int turn;

        if(stones < 1) {
            std::cout << " Du loser" << std::endl;
            return;
        }
        if(stones == 1) {
            std::cout << " Du hast nur Glueck gehabt" << std::endl;
            return;
        }

        turn = turns[stones %4];
        std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
        stones -= turn;
    }

    bool is_game_over() {
        return stones < 1;
    }

};
