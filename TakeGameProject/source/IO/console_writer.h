//
// Created by JoachimWagner on 13.10.2022.
//

#pragma once

#include <string>
#include "writer.h"

class console_writer :public writer{
public:
    void write(std::string message) const override {
        std::cout << message << std::endl;
    }
};




