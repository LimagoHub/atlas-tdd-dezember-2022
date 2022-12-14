//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include "../games/game.h"

class game_client {

    game & game_;

public:
    game_client(game &game) : game_(game) {}

    void go() {
        game_.play();
    }
};




