//
// Created by JoachimWagner on 26.06.2023.
//

#include "MyServiceUsingDepengencyTest.h"

TEST_F(MyServiceUsingDepengencyTest, demo) {

//    // Recordmode
//    EXPECT_CALL(dependencyMock, bar())
//        .WillOnce(Return(4711))
//        .WillOnce(Return(97))
//        .WillOnce(Throw(std::exception{"Upps"}));
//
//
//    // Replay
//    for (int i = 0; i < 3; ++i) {
//        std::cout << dependencyMock.bar() << std::endl;
//    }

    EXPECT_CALL(dependencyMock, foobar("Hello")).Times(AnyNumber()).WillOnce(Return(42));
    EXPECT_CALL(dependencyMock, foobar("Hallo")).Times(AnyNumber()).WillOnce(Return(4711));
    auto result = dependencyMock.foobar("Hallo");

    std::cout << result << std::endl;
}

TEST_F(MyServiceUsingDepengencyTest, abc_bla_bla) {
    // Arrange + Assertion
    EXPECT_CALL(dependencyMock, foo("HALLO")).Times(1);

    // Act
    objectUnderTest.abc("hallo");
}

TEST_F(MyServiceUsingDepengencyTest, bcd_bla_bla) {
    // Arrange + Assertion
    EXPECT_CALL(dependencyMock, bar()).Times(AtLeast(1)).WillRepeatedly(Return(2));

    // Act
    auto result = objectUnderTest.bcd();

    // Assertion
    EXPECT_THAT(result, Eq(9));
}