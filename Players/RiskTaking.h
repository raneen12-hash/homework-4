
#include "Character.h"
#include "../Utilities.h"
#include <string>

class RiskTaking : public Character{
    string m_type;
public:
//C'tor + big 3
    RiskTaking(string type);
    RiskTaking& operator=(const RiskTaking& other) = default;
    ~RiskTaking() = default;
//clone instead of copy
    Character* clone() const override;
    void buy(Player& player) override;
    string getType() const override;

};

