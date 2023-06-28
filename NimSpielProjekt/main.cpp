#include <iostream>
#include "game/NimGame/nim_game_impl.h"
#include "client/GameClient.h"

int main() {
    nim_game_impl game;
    GameClient client{game};
    client.go();
    return 0;
}
