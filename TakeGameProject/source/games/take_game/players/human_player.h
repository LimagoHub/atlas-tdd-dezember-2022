//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include <iostream>
#include "abstract_take_game_player.h"

class human_player : public abstract_take_game_player{

public:
    human_player(const std::string &name) : abstract_take_game_player(name) {}

    int do_turn(const int &stones) const override {
        int move;
        std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
        std::cin >> move;
        return move;
    }
};




