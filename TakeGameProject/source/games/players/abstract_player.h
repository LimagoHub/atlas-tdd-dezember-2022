//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once

#include <string>
#include "player.h"

template<class BOARD, class MOVE>
class abstract_player :public player<BOARD,MOVE> {

    std::string name;
public:
    abstract_player(const std::string &name) : name(name) {

    }

    std::string getName() const override {
        return name;
    }
};




