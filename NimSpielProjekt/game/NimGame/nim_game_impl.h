//
// Created by JoachimWagner on 28.06.2023.
//

#pragma once


#include <iostream>
#include "../game.h"

class nim_game_impl : public game{
   int stones;
   int turn;

public:
    nim_game_impl():stones(23){}
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
        if(is_game_over()) return ;

        while(true) {
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1, 2 oder 3." << std::endl;
            std::cin >> turn;
            if(turn >= 1 && turn <= 3) break;
            std::cout << "Ungültiger Zug" << std::endl;
        }

        terminate_turn("Spieler");

    }



    void computer_zug() {

        if(is_game_over()) return ;

        const  int turns [] = {3,1,1,2};

        turn = turns[stones %4];
        std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
        terminate_turn("Computer");
    }

    void terminate_turn(std::string player) {
        updateBoard();
        print_game_over_message_if_game_is_over(player);
    }

    void print_game_over_message_if_game_is_over(const std::string &player) {
        if(is_game_over())
            std::cout << player << " hat verloren"  << std::endl;
    }

    // Im Sumpf
    void updateBoard() { stones -= turn; }

    bool is_game_over() {
        return stones < 1;
    }

};
