//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include <iostream>
#include <vector>
#include "../game.h"

#include "../abstract_game.h"
class take_game_impl :public abstract_game<int,int>{


protected:

    bool is_move_valid() const override{
        return getMove() >= 1 && getMove() <= 3;
    }

    void update_board() override { setBoard(getBoard() - getMove()); }

    bool is_gameover() const override{
        return getBoard() < 1 || getPlayers().empty();
    }

    void prepare() override {
        write(getCurrentPlayer()->getName() + " ist am Zug.");
    }

public:
    take_game_impl(writer &writer) : abstract_game(writer) {
        setBoard(23);
    }


};




