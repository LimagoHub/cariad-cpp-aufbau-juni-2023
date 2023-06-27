//
// Created by JoachimWagner on 27.06.2023.
//

#include "personen_service_impl_test.h"


TEST_F(personen_service_impl_test, speichern__vorname_zu_kurz__throws_personen_service_exception){
    try {
        // Arrange
        person invalid_person{"J", "Doe"};

        // Act
        objectUnderTest.speichern(invalid_person);
        FAIL() << "Exception erwartet";
    } catch (const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Vorname zu kurz"));
    }
}

TEST_F(personen_service_impl_test, speichern__nachname_zu_kurz__throws_personen_service_exception){
    try {
        // Arrange
        person invalid_person{"John", "D"};

        // Act
        objectUnderTest.speichern(invalid_person);
        FAIL() << "Exception erwartet";
    } catch (const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Nachname zu kurz"));
    }
}

TEST_F(personen_service_impl_test, speichern__blacklistedPerson__throws_personen_service_exception){
    try {
        // Arrange
        person blacklisted_person{"John", "Doe"};

        EXPECT_CALL(blacklistMock, is_blacklisted(blacklisted_person)).WillOnce(Return(true));

        // Act
        objectUnderTest.speichern(blacklisted_person);
        FAIL() << "Exception erwartet";
    } catch (const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrCaseEq("Blacklisted Person"));
    }
}
TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_underlying_service__throws_personen_service_exception){
    try {
        // Arrange
        person valid_person{"John", "Doe"};
        // Recordmode
        EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(Throw(std::out_of_range{"upps"}));

        // Act
        objectUnderTest.speichern(valid_person);
        FAIL() << "Exception erwartet";
    } catch (const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrCaseEq("Ein Fehler ist aufgetreten"));
        EXPECT_THAT(ex.getNestedException(), NotNull());
    }
}

TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_underlying_blacklist_service__throws_personen_service_exception){
    try {
        // Arrange
        person valid_person{"John", "Doe"};
        // Recordmode
        EXPECT_CALL(blacklistMock, is_blacklisted(_)).WillOnce(Throw(std::out_of_range{"upps"}));

        // Act
        objectUnderTest.speichern(valid_person);
        FAIL() << "Exception erwartet";
    } catch (const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrCaseEq("Ein Fehler ist aufgetreten"));
        EXPECT_THAT(ex.getNestedException(), NotNull());
    }
}

TEST_F(personen_service_impl_test, speichern__happyDay__person_passed_to_repo){

        // Arrange + Assertion
        InSequence s;
        person valid_person{"John", "Doe"};
        // Recordmode
        EXPECT_CALL(blacklistMock, is_blacklisted(valid_person)).WillOnce(Return(false));
        EXPECT_CALL(repoMock, save_or_update(valid_person));


    // Nur in Kombination mit NiceMock sinnvoll
        //ON_CALL(blacklistMock,is_blacklisted(_)).WillByDefault(Return(false));
        // Act
        objectUnderTest.speichern(valid_person);

}
TEST_F(personen_service_impl_test, speichern_overloaded__HappyDay__person_passed_to_repo){

    // Arrange
    person captured_person{};
    EXPECT_CALL(blacklistMock, is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(DoAll(SaveArg<0>(&captured_person)));

    // ACT
    objectUnderTest.speichern("Max","Mustermann");


    //Assertion
    EXPECT_THAT( captured_person.getVorname(), AnyOf(StartsWith("J"), StartsWith("M")));
    EXPECT_THAT(captured_person.getNachname(), AnyOf(Eq("Doe"), Eq("Mustermann")));
    EXPECT_THAT(captured_person.getId(), Not(IsEmpty()));
}



// Automatischer Aufruf vor jedem Test
void personen_service_impl_test::SetUp() {
    ON_CALL(blacklistMock,is_blacklisted(_)).WillByDefault(Return(false));
}
