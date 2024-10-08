//
// Created by Raneen Haj Yahya on 18/08/2024.
//


#include "Event.h"
#include <string>
using std::string;
 string Event::beastType() const{
   return " " ;
}
int Event::getLoot() const{
    return 0;
}
int Event::getDamage() const {
    return 0;
}

//SolarEclipse

string SolarEclipse::getDescription() const{
    return "SolarEclipse";
}
int SolarEclipse::getCombatPower() const{
    return 0;
}
void SolarEclipse::applyEvent(Player& player) {
    player.playSolarEclipse();
}

//PotionsMerachant

string PotionsMerchant::getDescription() const{
    return "PotionsMerchant";
}
int PotionsMerchant::getCombatPower() const{
    return 0;
}
void PotionsMerchant::applyEvent(Player& player) {
    player.playPotionsMerchant();
}

//encounter
Encounter::Encounter(int power, int loot, int damage) :
        m_power(power), m_loot(loot), m_damage(damage){}

string Encounter::getDescription() const{
    return beastType() + " (power " + to_string(getCombatPower()) +
           ", loot " + to_string(getLoot()) + ", damage "
           + to_string(getDamage()) +")";
}

int Encounter::getCombatPower() const{
    return m_power;
}

int Encounter::getLoot() const{
    return m_loot;
}

int Encounter::getDamage() const{
    return m_damage;
}

//Pack
Pack::Pack(const int power,const int loot,const int damage,const int size ,const int num_balrog) : Encounter(power,loot,damage),num_balrog(num_balrog),size(size){

}
void Pack::setPwoer()
{
     m_power+=num_balrog*2;
}

string Pack::getDescription() const {
    return beastType() +" of "+ to_string(size)+" members "+"(power " + to_string(getCombatPower()) +
           ", loot " + to_string(getLoot()) + ", damage "
           + to_string(getDamage()) +")";
}


void Pack::applyEvent(Player& player) {
    player.applyEncounter(*this);
    setPwoer();
}

string Pack::beastType() const{
    return "Pack";
}
//Snail
Snail::Snail() : Encounter(5,2,10){}

void Snail::applyEvent(Player& player) {
    player.applyEncounter(*this);
}

string Snail::beastType() const{
    return "Snail";
}


//Slime
Slime::Slime() : Encounter(12,5,25){}

void Slime::applyEvent(Player& player) {
    player.applyEncounter(*this);
}

string Slime::beastType() const{
    return "Slime";
}

//Balrog
Balrog::Balrog() : Encounter(15,100,9001){}

void Balrog::applyEvent(Player& player) {
    player.applyEncounter(*this);
}

string Balrog::beastType() const{
    return "Balrog";
}
void Event::setCompatPower() {

}
void Encounter::setCompatPower() {
    m_power+=2;
}
