//
// Created by JoachimWagner on 31.05.2022.
//

#ifndef EURO2DOLLAR_MOCKEURO_TO_DOLLAR_CALCULATOR_H
#define EURO2DOLLAR_MOCKEURO_TO_DOLLAR_CALCULATOR_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../services/euro_to_dollar_calculator.h"

class Mockeuro_to_dollar_calculator : public euro_to_dollar_calculator {
public:
    MOCK_METHOD( double , convert, (const double euro), (const, override));
};


#endif //EURO2DOLLAR_MOCKEURO_TO_DOLLAR_CALCULATOR_H
