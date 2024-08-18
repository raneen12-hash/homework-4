
#include "Responsible.h"

Responsible::Responsible(string type) : m_type(type){}

void Responsible::buy(Player& player){
    int counter = 0;
    while( (player.getHealthPoints() <= 100) && player.pay(5)){
        player.heal(10);
        counter++;
    }
    cout<<getPotionsPurchaseMessage(player, counter)<<endl;
}

string Responsible::getType() const{
    return m_type;
}

Character* Responsible::clone() const{
    return new Responsible(*this);
}
