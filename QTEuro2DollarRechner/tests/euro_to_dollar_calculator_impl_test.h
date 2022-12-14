//
// Created by JoachimWagner on 30.05.2022.
//

#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../services/euro_to_dollar_calculator_impl.h"
#include "Mockexchange_rate_service.h"
class euro_to_dollar_calculator_impl_test : public testing::Test{
protected:
    Mockexchange_rate_service exchange_rate_service_mock;
    euro_to_dollar_calculator_impl object_under_test{exchange_rate_service_mock};
};




