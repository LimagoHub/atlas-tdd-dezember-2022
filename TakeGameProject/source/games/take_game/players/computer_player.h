//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include <iostream>
#include "abstract_take_game_player.h"

class computer_player :public abstract_take_game_player {


public:
    computer_player(const std::string &name) : abstract_take_game_player(name) {

    }

    int do_turn(const int &stones) const override {

        const int moves[] = {3,1,1,2};
        int move = moves[stones % 4];
        std::cout << "Computer nimmt " << move << " Steine." << std::endl;
        return move;
    }
};




