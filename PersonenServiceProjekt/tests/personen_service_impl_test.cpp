//
// Created by JoachimWagner on 13.12.2022.
//

#include "personen_service_impl_test.h"

TEST_F(personen_service_impl_test, speichern__vorname_zu_kurz__throws_personen_service_exception) {
    // Arrange
    person invalid_person{"J", "Doe"};

    try {
        object_under_test.speichern(invalid_person);
        FAIL() << "Exception expected";
    } catch(const personen_service_exception & ex) {
        EXPECT_STREQ("Vorname zu kurz", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern__nachname_zu_kurz__throws_personen_service_exception) {
    // Arrange
    person invalid_person{"John", "D"};

    try {
        object_under_test.speichern(invalid_person);
        FAIL() << "Exception expected";
    } catch(const personen_service_exception & ex) {
        EXPECT_STREQ("Nachname zu kurz", ex.what());
    }
}
