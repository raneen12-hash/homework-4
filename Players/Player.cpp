
// Created by Raneen Haj Yahya on 17/08/2024.
//
#include "Magician.h"
#include "Archer.h"
#include "../Utilities.h"
#include "Player.h"
#include "Job.h"
#include "Warrior.h"
#include "Character.h"
#include "Responsible.h"
#include "RiskTaking.h"
#include "../Exception.h"

//Ctor
Player::Player(const string name, const string job, const string character) :
        m_name(name), m_maxHP(DEFAULTmaxHP), m_HP(DEFAULTmaxHP),
        m_coins(10), m_level(1), m_force(DEFAULTFORCE) {
    if (job == "Warrior") {
        m_job = new Warrior("Warrior");
        m_HP = 150;
        m_maxHP =150;
    }
    else if(job =="Archer"){
        m_job = new Archer("Archer");
        m_coins =20 ;
    }
    else if(job =="Magician") {
        m_job = new Magician("Magician");
    }
    else {
        throw InvalidPlayersFile();
    }
    if (character == "Responsible") {
        m_character = new Responsible("Responsible");
    }
    else if(character =="RiskTaking")
    {
        m_character = new RiskTaking("RiskTaking");
    }
    else
    { delete m_job;
        throw InvalidPlayersFile();
    }
}

//copy ctor
Player::Player(const Player& other){
    m_job=other.m_job->clone();
    m_character=other.m_character->clone();
}

void Player::levelUp(){
    m_level = (m_level == 10) ? m_level : m_level+1;
}

int Player :: getLevel() const{
    return m_level;
}

void Player::buff(int buffForce){
    m_force += buffForce;
}

void Player :: heal(int healHP){
    if(healHP > 0)
    {
        if(m_HP+healHP> m_maxHP)
        {
            m_HP=m_maxHP;
        }
        else
        {
            m_HP= m_HP+healHP;
        }
    }
}

void Player::damage(int damageHP){
    m_HP -= damageHP;
    if(m_HP < 0){
        m_HP = 0;
    }
}

bool Player :: isKnockedOut () const {
    if(m_HP == 0)
    {
        return true ;
    }
    return false;
}

void Player::addCoins(int getcoins){
    m_coins += getcoins;
}

bool Player :: pay (int paycoins){
    if(paycoins>0)
    {
        if(paycoins <= m_coins)
        {
            m_coins -= paycoins;
            return true;
        }
        else
        {
            return false ;
        }
    }
    return false;
}

string Player::getDescription() const{
    return m_name + ", " + m_job->getJob() + " with " + m_character->getType() +
           " behavior (level " + to_string(m_level) + ", force "
           + to_string(m_force)+")";
}
string Player::getName() const{
    return m_name;
}

int Player::getForce() const{
    return m_force;
}

int Player::getHealthPoints() const{
    return m_HP;
}

int Player::getCoins() const{
    return m_coins;
}

int Player::getCombatPower(){
    return m_job->getcombat(*this);
}

void Player::playSolarEclipse(){
    m_job->playSolarEclipse(*this);
}

void Player::playPotionsMerchant(){
    m_character->buy(*this);
}

void Player::applyEncounter(const Event& event){
    int playerCombatPower = getCombatPower();
    int eventCombatPower = event.getCombatPower();
    int loot = event.getLoot();
    int damage = event.getDamage();
    if(playerCombatPower > eventCombatPower){
        this->levelUp();
        this->addCoins(loot);
        cout<<getEncounterWonMessage(*this, loot)<<endl;
    }
    else{
        this->damage(damage);
        cout<<getEncounterLostMessage(*this , damage)<<endl;
    }
}
Player::~Player(){
    delete m_job;
    delete m_character;
}




