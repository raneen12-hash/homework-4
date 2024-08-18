//
// Created by hadis on 19/08/2024.
//

#ifndef ARCHER_H
#define ARCHER_H

#include "Job.h"
class Archer : public Job{
    string m_type;
public:
//C'tor + big 3
    Archer(string type);
    Archer& operator=(const Archer& archer) = default;
    ~Archer() = default;
//clone instead of copy
    Job* clone() const override;
    int getcombat(Player& player) override;
    void playSolarEclipse(Player& player) override;
    string getJob() const override;
};

#endif //UNTITLED10_ARCHER_H

