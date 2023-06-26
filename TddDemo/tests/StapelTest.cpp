//
// Created by JoachimWagner on 26.06.2023.
//

#include "StapelTest.h"

TEST_F(StapelTest, abc) {
    EXPECT_TRUE(objectUnderTest.is_empty());
}

TEST_F(StapelTest, bcd) {
    objectUnderTest.push(1);
    EXPECT_FALSE(objectUnderTest.is_empty());
}
