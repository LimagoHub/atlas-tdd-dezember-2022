//
// Created by JoachimWagner on 13.12.2022.
//

#include "personen_service_impl_test.h"
#include <stdexcept>

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

TEST_F(personen_service_impl_test, speichern__unerwuenschte_person__throws_personen_service_exception) {
    // Arrange
    person invalid_person{"John", "Doe"};

    EXPECT_CALL(blackListMock, is_blacklisted(invalid_person)).WillOnce(Return(true));
    EXPECT_CALL(repoMock,save_or_update(_)).Times(0);
    try {
        object_under_test.speichern(invalid_person);
        FAIL() << "Exception expected";
    } catch(const personen_service_exception & ex) {
        EXPECT_STREQ("Unerwuenschte Person", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern__exception_in_underlying_service__throws_personen_service_exception) {
    // Arrange
    person valid_person{"Max", "Mustermann"};

    EXPECT_CALL(repoMock,save_or_update(_)).WillOnce(Throw(std::out_of_range{"Ein Fehler ist aufgetreten"}));

    try {
        object_under_test.speichern(valid_person);
        FAIL() << "Exception expected";
    } catch(const personen_service_exception & ex) {
        EXPECT_STREQ("Fehler beim Speichern", ex.what());
    }
}
TEST_F(personen_service_impl_test, speichern__happy_day__person_passed_to_repo) {
    // Arrange
    InSequence dummy;
    person valid_person{"Max", "Mustermann"};



    ON_CALL(blackListMock, is_blacklisted(_)).WillByDefault(Return(false));
    EXPECT_CALL(repoMock,save_or_update(valid_person)).Times(1);


    object_under_test.speichern(valid_person);


}


void personen_service_impl_test::SetUp() {
    ON_CALL(blackListMock, is_blacklisted(_)).WillByDefault(Return(false));
}
