//
// Created by JoachimWagner on 14.12.2022.
//

#include "computer_player_test.h"

TEST_P(computer_player_parameter_test, do_turn_steine_durch_4_teilbar_returns3) {

    EXPECT_CALL(writerMock, write("Computer nimmt " + std::to_string(expectedResult) + " Steine."));
    EXPECT_THAT(object_under_test.do_turn(stones), Eq(expectedResult));
}


INSTANTIATE_TEST_SUITE_P(
        DoTurnHappyDayParameterTests, // Name der Tests, frei waehlbar
        computer_player_parameter_test, // Verbindung zur Testklasse
        Values(
                std::make_pair(20, 3),
                std::make_pair(21, 1),
                std::make_pair(22, 1),
                std::make_pair(23, 2),
                std::make_pair(4, 3),
                std::make_pair(5, 1),
                std::make_pair(6, 1),
                std::make_pair(7, 2))
);