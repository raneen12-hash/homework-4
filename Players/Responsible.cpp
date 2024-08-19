
#include "Responsible.h"

Responsible::Responsible(string type) : m_type(type){}

void Responsible::buy(Player& player){
    int counter = 0,temp=100;
    if(player.getjob()=="Warrior"){
        temp=150;
    }
    while( (player.getHealthPoints() < temp) && player.pay(5)){
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
