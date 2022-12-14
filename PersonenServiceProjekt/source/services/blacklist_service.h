//
// Created by JoachimWagner on 13.12.2022.
//

#pragma once

#include "../persistence/person.h"
class blacklist_service {

public:
    virtual bool is_blacklisted(const person &person_) const = 0;

};




