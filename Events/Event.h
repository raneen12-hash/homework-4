
#pragma once

#include "../Players/Player.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Event {
public:
//C'tor + big 3
    Event() = default;
    Event(const Event& Event) = delete;
    Event& operator=(const Event& Event) = delete;
    virtual ~Event() = default;

//Event functions
    /**
     * Gets the description of the Event
     *
     * @return - the description of the Event
    */
    virtual string beastType() const;
    virtual string getDescription() const = 0;
    virtual void applyEvent(Player& player)  = 0;
    virtual int getCombatPower() const = 0;
    virtual int getLoot() const ;
    virtual int getDamage() const ;

    virtual void setCompatPower();
};

class Special_Event : public Event{
public:
    virtual string getDescription() const = 0;
};

class SolarEclipse : public Special_Event{
public:
//C'tor + big 3
    SolarEclipse() = default;
    SolarEclipse(const SolarEclipse& other) = delete;
    SolarEclipse& operator=(const SolarEclipse& other) = delete;
    ~SolarEclipse() = default;
    int getCombatPower() const override;

//SolareEclipse Functions
    string getDescription() const override;
    void applyEvent(Player& Player)  override;
};


class PotionsMerchant : public Special_Event{
public:
//C'tor + big 3
    PotionsMerchant() = default;
    PotionsMerchant(const PotionsMerchant& other) = delete;
    PotionsMerchant& operator=(const PotionsMerchant& other) = delete;
    ~PotionsMerchant() = default;
    int getCombatPower() const override;


    //PotionsMerchant functions
    string getDescription() const override;
    void applyEvent(Player& Player)  override;
};

class Encounter : public Event {
public:
//C'tor + big 3
    Encounter(int power, int loot, int damage);
    Encounter(const Encounter&) = delete;
    Encounter& operator=(const Encounter&) = delete;
    virtual ~Encounter() = default;

//Encounter Functions
    virtual string getDescription() const override;
    virtual int getCombatPower() const override ;
    int getLoot() const override;
    int getDamage() const override;
    virtual void applyEvent(Player& player)  override = 0 ;
    virtual string beastType() const override = 0;
protected:
    int m_power;
    int m_loot;
    int m_damage;

    void setCompatPower() override;
};

class Pack: public Encounter {
public:
//C'tor + big 3
    Pack(const Pack& other) = delete;
    Pack(const int power, const int loot, const int damage, const int size,int num);
    Pack& operator=(const Pack& other) = delete;
    ~Pack() = default;

//Gang functions
    void applyEvent(Player& player)  override;
    string getDescription() const override;
    string beastType() const override;
    int getNumOfBalrog() ;
    void setPwoer();
private:
    int num_balrog;
    int size;
};

class Snail : public Encounter {
public:
//C'tor + big 3
    Snail();
    Snail(const Snail& other) = delete;
    Snail& operator=(const Snail& other) = delete;
    ~Snail() = default;

//Goblin functions
    void applyEvent(Player& player)  override;
    string beastType() const override;
};

class Slime : public Encounter {
public:
//C'tor + big 3
    Slime();
    Slime(const Slime& other) = delete;
    Slime& operator=(const Slime& other) = delete;
    ~Slime() = default;

//Giant functions
    void applyEvent(Player& player)  override;
    string beastType() const override;
};

class Balrog : public Encounter {
public:
//C'tor + big 3
    Balrog();
    Balrog(const Balrog& other) = delete;
    Balrog& operator=(const Balrog& other) = delete;
    ~Balrog() = default;

//Dragon functions
    void applyEvent(Player& player)  override;
    string beastType() const override;
};




