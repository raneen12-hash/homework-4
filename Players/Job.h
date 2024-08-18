#ifndef UNTITLED6_JOB_H
#define UNTITLED6_JOB_H

#pragma once
#include "Player.h"
#include <string>
#include "../Utilities.h"
using std::string;

class Player;
class Job {
public:
//C'tors / big 3
    Job() = default;
    Job& operator=(const Job& job) = default;
    virtual ~Job() = default;
//clone instead of copy
    virtual Job* clone() const=0;
//virtual functions
    virtual string getJob() const = 0;
    virtual int getcombat(Player& player)=0;
    virtual void playSolarEclipse(Player& player)=0;
};

#endif

