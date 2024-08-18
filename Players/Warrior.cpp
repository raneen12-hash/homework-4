
#include "Warrior.h"

Warrior::Warrior(string type) : m_type(type){}

int Warrior::getcombat(Player& player) {
    int combat = 2*(player.getForce()) + player.getLevel();
    return combat;
}

void Warrior::playSolarEclipse(Player& player){
    int effect = 0;
    if(player.getForce() != 0){
        player.buff(-1);
        effect = -1;
    }
    cout<<getSolarEclipseMessage(player,effect)<<endl;
}

string Warrior::getJob() const{
    return m_type;
}

Job* Warrior::clone() const{
    return new Warrior(*this);
}
