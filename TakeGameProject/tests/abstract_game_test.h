//
// Created by JoachimWagner on 13.10.2022.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MyAbstractGameDummy.h"


#include "DummyClassesForTest.h"
#include "Mockplayer.h"
#include "Mockwriter.h"
using namespace testing;


class abstract_game_test : public Test{
protected:
    NaggyMock<Mockwriter> writer_mock;
    NiceMock<Mockplayer> game_player_mock;
    MyAbstractGameDummy object_under_test{writer_mock};

    void SetUp() override {
        object_under_test.addPlayer(&game_player_mock);
        ON_CALL(game_player_mock, getName()).WillByDefault(Return("Mockplayer"));
    }
};




