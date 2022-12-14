//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include "../../players/abstract_player.h"

class abstract_take_game_player :public abstract_player<int,int>{



public:
    abstract_take_game_player(const std::string &name) : abstract_player<int, int>(name) {}



};




