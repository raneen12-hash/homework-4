
#ifndef UNTITLED6_SORCERER_H
#define UNTITLED6_SORCERER_H

#pragma once
#include "Job.h"

class Magician : public Job{
    string m_type;
public:
//C'tor + big 3
    Magician(string type);
    Magician& operator=(const Magician& magician) = default;
    ~Magician() = default;
//clone instead of copy
    Job* clone() const override;
    int getcombat(Player& player) override;
    void playSolarEclipse(Player& player) override;
    string getJob() const override;
};



#endif //UNTITLED6_SORCERER_H