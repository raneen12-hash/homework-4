
#ifndef BEHAVIOR_H
#define BEHAVIOR_H


#include <string>
#include "Player.h"
using std::string;

class Character  {
public:
//C'tor + big 3
    Character() = default;
    Character& operator=(const Character& behavior) = default;
    virtual ~Character() = default;
//clone instead of copy
    virtual Character* clone() const = 0;
    virtual void buy(Player& player)=0;
    virtual string getType() const = 0;

};
#endif
