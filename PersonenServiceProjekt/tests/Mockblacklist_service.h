#pragma once

#include "gmock/gmock.h"

#include "../source/persistence/person.h"
#include "../source/services/blacklist_service.h"



class Mockblacklist_service : public blacklist_service {
 public:
   MOCK_METHOD(bool, is_blacklisted, (const person & possibleBlacklistedPerson), (const, override));
};
