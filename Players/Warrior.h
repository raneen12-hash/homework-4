#ifndef WARIOR_H
#define WARIOR_H

#include "Job.h"

class Warrior : public Job{
    string m_type;
public:
//C'tor + big 3
    Warrior(string type);
    Warrior& operator=(const Warrior& warior) = default;
    ~Warrior() = default;
//clone instead of copy
    int getcombat(Player& player) override;
//Warior functions
    void playSolarEclipse(Player& player) override;
    string getJob() const override;
    Job* clone() const override;
};
#endif
