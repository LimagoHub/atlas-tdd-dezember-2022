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

TEST_F(euro_to_dollar_presenter_impl_test, beenden__happy_day__dispose_invoked){
    EXPECT_CALL(euro_to_dollar_viewMock, dispose());
    object_under_test.beenden();
}


TEST_F(euro_to_dollar_presenter_impl_test, populate_items__happy_day__mask_is_filled_with_defaults){
    EXPECT_CALL(euro_to_dollar_viewMock, set_euro("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));
    object_under_test.populate_items();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__read_euro_from_mask){
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro());
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__nan_in_euro_field__error_message_in_dollar_field){
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("Not a Number"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl"));
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__unexpected_exception_in_underlying_service__error_message_in_dollar_field){
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("10"));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(testing::_)).WillOnce(testing::Throw(std::out_of_range{"upps"}));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Fehler im Service"));
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__valid_euro_value_from_mask__euro_value_passed_to_service){
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("10"));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10.0)).Times(1);

    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__happy_day__dollar_value_in_mask){
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("10"));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10.0)).Times(1).WillOnce(testing::Return(1000.0));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("1000.000000"));
    object_under_test.rechnen();
}


TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state__nan_in_euro_field__rechnen_disabled){
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("Not a Number"));

    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(false));
    object_under_test.update_rechnen_action_state();
}

TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state__valid_number_in_euro_field__rechnen_enabled){
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("10"));

    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));
    object_under_test.update_rechnen_action_state();
}