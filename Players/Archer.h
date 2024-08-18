
#ifndef UNTITLED6_SORCERER_H
#define UNTITLED6_SORCERER_H
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



#endif //UNTITLED6_SORCERER_H