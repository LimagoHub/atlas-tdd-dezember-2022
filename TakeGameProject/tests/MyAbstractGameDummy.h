//
// Created by JoachimWagner on 13.10.2022.
//

#pragma once
#include "../source/games/abstract_game.h"
#include "DummyClassesForTest.h"

class MyAbstractGameDummy :public abstract_game<DummyBoard,DummyMove>{
public:
    bool game_over{ false };
    bool move_valid{ true };
    MyAbstractGameDummy(writer &writer) : abstract_game(writer) {}

protected:
    bool is_move_valid() const override {
        return move_valid;
    }

    void update_board() override {
        // Ok (PAL)
    }

    bool is_gameover() const override {
        return game_over;
    }
};




