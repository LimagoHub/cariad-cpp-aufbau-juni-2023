//
// Created by JoachimWagner on 29.06.2023.
//

#pragma once


#include <string>
template<class BOARD, class TURN>
class player {
public:
    virtual std::string get_name() const = 0;
    virtual TURN do_turn(const BOARD &board) const = 0;
};
