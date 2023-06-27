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
