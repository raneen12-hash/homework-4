//
// Created by Raneen Haj Yahya on 28/03/2024.
//

#include "RiskTaking.h"
RiskTaking::RiskTaking(string type) : m_type(type){}

void RiskTaking :: buy(Player& player) {
    int count =0;
    if(player.getCoins()>=5 && player.getHealthPoints()<50)
    {
        player.pay(5);
        player.heal(10);
        count=1;
    }
    cout<<getPotionsPurchaseMessage(player, count)<<endl;


}

string RiskTaking :: getType() const {
    return m_type;
}

Behavior* RiskTaking::clone() const{
    return new RiskTaking(*this);
}
