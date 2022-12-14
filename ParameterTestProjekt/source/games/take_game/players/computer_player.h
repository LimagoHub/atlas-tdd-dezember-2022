//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include <iostream>

class computer_player {


public:


    int do_turn(const int &stones) const  {

        const int moves[] = {3,1,1,2};
        int move = moves[stones % 4];
        std::cout << "Computer nimmt " << move << " Steine." << std::endl;
        return move;
    }
};




