

//
// Created by Raneen Haj Yahya on 24/03/2024.
//

#ifndef UNTITLED6_PLAYER_H
#define UNTITLED6_PLAYER_H

#pragma once
#include <stdbool.h>
#include <string>
#include <iostream>
#include "Exception.h"



class Job;
class Character;
class Event;
using namespace std;

class Player{
private:
    string m_name;
    int m_maxHP;
    int m_HP;
    int m_coins;
    int m_level;
    int m_force;
    Job* m_job;
    Character* m_character;
    static const int DEFAULTmaxHP =100;
    static const int DEFAULTFORCE =5;
public:
    /**
     * @brief Construct a new Player object
     *
     * @param name - the name of the player
     * @param job - job type
     * @param behavior - behavior type
     */
    Player(const string name, const string job, const string character);

    /**
     * @brief Copy constructor of the Player
     *
     * @param player - the player theat will be copied
     */
    Player(const Player& other);


    /**
     * @brief assignment operator
     *
     * @param other - the other is a player that will be equedled to another player
     *
     * @return Player& - player that we want to make it equal to other
     */
    Player& operator=(const Player& other)=default;

    /**
    * @brief Destroy the Player
    *
    */
    ~Player();


    /**
     * @brief make the level up of the player
     *
     */
    void levelUp();

    /**
     * @brief Get the Level of player
     *
     * @return int returns the level of the player
     */
    int getLevel() const;

    /**
     * @brief buff the players force by additional force
     *
     * @param additionalForce - the amount of force that will be added to the player
     */
    void buff(int buffForce);

    /**
     * @brief heal the player by additional hp
     *
     * @param additionalHP - the amount of hp that will be added to player
     */
    void heal(int healdHP);

    /**
     * @brief damage player by damageHP
     *
     * @param damageHP - the amount of damage that will be deduced from the player
     */
    void damage(int damageHP);

    /**
     * @brief returns if player is knocked out
     *
     * @return true - player is knocked out
     * @return false - player isn't knocked out
     */
    bool isKnockedOut() const;

    /**
     * @brief adds coins to the player by additional coins
     *
     * @param additionalCoins - the amount of gold that willl be added to the player
     */
    void addCoins(int getcoins);

    /**
     * @brief the player pay amount of money equals to damageConis
     *
     * @param damageCoins - the amount of gold that will be deduced from the player
     * @return true - if the player can afford the amount of gold
     * @return false - if the player can not afford the amount of gold
     */
    bool pay(int paycoins);

    /**
     * @brief Get the job of the player
     *
     * @return int returns the job of the player
     */
    string getjob() const;  //change:: not virtual

    /**
     * @brief Get the behavior of the player
     *
     * @return int returns the behavior of the player
     */
    int character() const; //change not virtual

    /* virtual Player* clone() const = 0; /// change: player isnt a base class / no inheritance

    void printInfo(std::ostream& os ) const;

    friend std::ostream& operator<<(std::ostream& os,const Player& player);
 */
    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;
    int getCombatPower();
    void setHealthPoints(int x);
    void playSolarEclipse() ;
    void playPotionsMerchant();
    void applyEncounter( Event& event);
};
#endif //UNTITLED6_PLAYER_H
