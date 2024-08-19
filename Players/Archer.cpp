
#include "Archer.h"


Archer::Archer(string type) : m_type(type){}

int Archer::getcombat(Player& player) {
    int combat = (player.getForce()) + player.getLevel();
    return combat;
}

void Archer::playSolarEclipse(Player& player){
    int effect=0;
    if(player.getForce() != 0){
        player.buff(-1);
        effect=-1;
    }
    cout<<getSolarEclipseMessage(player,effect)<<endl;

}

string Archer::getJob() const{
    return m_type;
}
Job* Archer::clone() const {
    return new Archer(*this);

}
