//
// Created by Raneen Haj Yahya on 28/03/2024.
//

#include "Magician.h"


Magician::Magician(string type) : m_type(type){}

int Magician::getcombat(Player& player) {
    int combat = (player.getForce()) + player.getLevel();
    return combat;
}

void Magician::playSolarEclipse(Player& player){
    int effect=0;
    if(player.getForce() != 0){
        player.buff(1);
        effect=1;
    }
    cout<<getSolarEclipseMessage(player,effect)<<endl;

}

string Magician::getJob() const{
    return m_type;
}

Job* Magician::clone() const{
    return new Magician(*this);
}
