//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once

template<class BOARD, class MOVE>
class player {
public:

    virtual std::string getName() const = 0;

    virtual MOVE do_turn(const BOARD & board) const = 0;
};




