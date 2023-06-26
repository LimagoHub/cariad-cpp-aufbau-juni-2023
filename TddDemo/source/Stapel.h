//
// Created by JoachimWagner on 26.06.2023.
//

#pragma once


class Stapel {

    bool empty{true};
public:
    bool is_empty() {
        return empty;
    }

    void push(int i) {
        empty = false;
    }
};
