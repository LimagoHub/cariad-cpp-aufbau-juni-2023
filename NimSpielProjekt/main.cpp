#include <iostream>
#include "game/NimGame/nim_game_impl.h"
#include "client/GameClient.h"
#include "game/NimGame/player/human_player.h"
#include "game/NimGame/player/computer_player.h"
#include "io/ConsoleWriter.h"

int main() {

    ConsoleWriter writer;

    human_player fritz{"Fritz"};
    computer_player hal{"Hal"};
    nim_game_impl game{writer};

    game.add_player(&fritz);
    game.add_player(&hal);

    GameClient client{game};
    client.go();
    return 0;
}
