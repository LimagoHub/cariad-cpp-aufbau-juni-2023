//
// Created by JoachimWagner on 29.06.2023.
//

#include "abstract_game_test.h"
TEST_F(abstract_game_test, play_success) {
    EXPECT_CALL(game_player_mock, do_turn(_)).WillOnce([this](DummyBoard d){
        object_under_test.game_over = true;
        return DummyMove{};
    });
    EXPECT_CALL(writer_mock, write(Eq("Mockplayer hat verloren")));

    object_under_test.play();
}

TEST_F(abstract_game_test, play_mogeln) {
    object_under_test.move_valid = false;

    EXPECT_CALL(game_player_mock, do_turn(_)).WillRepeatedly([this](DummyBoard d) {
        object_under_test.game_over = true;
        return DummyMove{};
    });
    EXPECT_CALL(writer_mock, write(Eq("Ungueltiger Zug"))).WillOnce( [this](std::string s) { object_under_test.move_valid = true; });
    EXPECT_CALL(writer_mock, write(Eq("Mockplayer hat verloren")));
    object_under_test.play();



}