//
// Created by JoachimWagner on 19.10.2022.
//
#include "gtest/gtest.h"
#include "../source/games/take_game/players/computer_player.h"

#pragma once

using namespace testing;

class computer_player_test: public Test
{
protected:
    computer_player object_under_test{"Fritz"};
};




