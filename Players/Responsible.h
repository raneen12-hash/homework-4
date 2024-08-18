
#include "Character.h"
#include "../Utilities.h"
class Responsible : public Character{
    string m_type;
public:
//C'tor + big3
    Responsible(string type);
    Responsible& operator=(const Responsible& other) = default;
    ~Responsible() = default;
//clone
    Character* clone() const override;
//responsible function
    void buy(Player& player) override;
    string getType() const override;

};
