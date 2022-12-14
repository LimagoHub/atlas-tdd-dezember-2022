//
// Created by JoachimWagner on 31.05.2022.
//
#include <stdexcept>
#include "euro_to_dollar_presenter_impl_test.h"
#include <stdexcept>
void euro_to_dollar_presenter_impl_test::SetUp() {

    object_under_test.set_view(& euro_to_dollar_viewMock);
    object_under_test.set_model(&euro_to_dollar_calculatorMock);
}

TEST_F(euro_to_dollar_presenter_impl_test, beenden__happy_day__mask_disposed) {

    EXPECT_CALL(euro_to_dollar_viewMock, dispose()).Times(1);
    object_under_test.beenden();
}

TEST_F(euro_to_dollar_presenter_impl_test, populate_items__happy_day__mask_initialized ){

    EXPECT_CALL(euro_to_dollar_viewMock, set_euro("0")).Times(1);
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("0")).Times(1);
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true)).Times(1);
    object_under_test.populate_items();
}


TEST_F(euro_to_dollar_presenter_impl_test, rechnen__ungueltige_eingabe__errormessage_in_dollarfield ){

    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("Not a valid Number"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl")).Times(1);
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__exception_in_underlying_service__errormessage_in_dollarfield ){

    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("10.0"));
    EXPECT_CALL(euro_to_dollar_calculatorMock,convert(_)).Times(1).WillOnce(Throw(std::out_of_range{"upps"}));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Interner Fehler")).Times(1);
    object_under_test.rechnen();
}

//TEST_F(euro_to_dollar_presenter_impl_test, rechnen__valid_euro_value__euro_value_passed_to_service ){
//
//    InSequence s;
//    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("10.0"));
//    EXPECT_CALL(euro_to_dollar_calculatorMock,convert(DoubleNear(10.0, 0.000000001))).Times(1);
//
//    object_under_test.rechnen();
//}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__happy_day__write_result_to_dollar_field ){

    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("10.0"));
    EXPECT_CALL(euro_to_dollar_calculatorMock,convert(DoubleNear(10.0, 0.000000001))).Times(1).WillOnce(Return(47.11));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("47.110000")).Times(1);
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state__not_a_valid_number__rechnen_disabled ){

    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("Herbert"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(false));
    object_under_test.update_rechnen_action_state();
}

TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state__valid_number__rechnen_enabled){

    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("10"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));
    object_under_test.update_rechnen_action_state();
}