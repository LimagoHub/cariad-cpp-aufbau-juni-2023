//
// Created by JoachimWagner on 29.06.2023.
//

#pragma once

#include <vector>
#include <stdexcept>
#include "../io/Writer.h"
#include "game.h"
#include "player/player.h"

template<class BOARD, class TURN>
class abstract_game :public game{

    Writer &writer;
    BOARD board; // entspricht stones
    TURN turn;

    std::vector<player<BOARD, TURN> *> players;
    player<BOARD, TURN> * current_player;
public:
    explicit abstract_game(Writer &writer) : writer(writer) {}

    void add_player(player<BOARD, TURN> *player){
        players.push_back(player);
    }

    void remove_player(player<BOARD, TURN> *player){

        // TODO Implementieren
        throw std::out_of_range{"Not implemented yet"};
    }

    void play() override {  // (Pseudo)integration
        while(! is_game_over())
            play_single_round();

    }
private:

    void play_single_round() { // Integration
        for (auto player: players)
           prepare_players_turn(player);

    }

    void prepare_players_turn(player<BOARD, TURN> *player) {
        setCurrentPlayer(player);
        play_turn();
    }

    void play_turn() {// Integration
        if(is_game_over()) return ;
        do_current_player_turn();
        terminate_turn();
    }

    void terminate_turn() {
        updateBoard();
        print_game_over_message_if_game_is_over();
    }


    void do_current_player_turn()  {

        do {
            setTurn(current_player->do_turn(getBoard()));
        } while(turn_is_invalid());
    }


    bool turn_is_invalid() {
        if(is_turn_valid()) return false;
        write( "Ungueltiger Zug");
        return true;
    }

    void print_game_over_message_if_game_is_over() {  // Operationen
        if(is_game_over())
            write(current_player->get_name() + " hat verloren");
    }

protected:
    void write(std::string message) {
        writer.write(message);
    }

    const std::vector<player<BOARD, TURN> *> &getPlayers() const {
        return players;
    }

    player<BOARD, TURN> *getCurrentPlayer() const {
        return current_player;
    }

    void setCurrentPlayer(player<BOARD, TURN> *currentPlayer) {
        current_player = currentPlayer;
    }

    BOARD getBoard() const {
        return board;
    }

    void setBoard(BOARD board) {
        abstract_game::board = board;
    }

    TURN getTurn() const {
        return turn;
    }

    void setTurn(TURN turn) {
        abstract_game::turn = turn;
    }

    virtual bool is_turn_valid() const = 0;
    virtual bool  is_game_over() const = 0;
    virtual void updateBoard() = 0;
};
