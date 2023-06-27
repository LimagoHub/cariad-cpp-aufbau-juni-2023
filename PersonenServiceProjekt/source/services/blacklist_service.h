//
// Created by JoachimWagner on 27.06.2023.
//

#pragma once


#include "../persistence/person.h"

class blacklist_service {
public:
    virtual bool is_blacklisted(const person &possibleBlacklistedPerson) const = 0 ;

};
