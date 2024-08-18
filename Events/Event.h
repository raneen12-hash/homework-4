
#pragma once

#include "../Players/Player.h"

class Event {
public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    string getDescription() const;
};



#include <string>
#include <vector>
using std::string;
using std::vector;

class Card {
public:
//C'tor + big 3
    Card() = default;
    Card(const Card& card) = delete;
    Card& operator=(const Card& card) = delete;
    virtual ~Card() = default;

//Card functions
    /**
     * Gets the description of the card
     *
     * @return - the description of the card
    */
    virtual string getDescription() const = 0;
    virtual void applyCard(Player& player) const = 0;
    virtual int getCombatPower() const = 0;
    virtual int getLoot() const ;
    virtual int getDamage() const ;
};

class Event : public Card{
public:
    virtual string getDescription() const = 0;
};

class SolarEclipse : public Event{
public:
//C'tor + big 3
    SolarEclipse() = default;
    SolarEclipse(const SolarEclipse& other) = delete;
    SolarEclipse& operator=(const SolarEclipse& other) = delete;
    ~SolarEclipse() = default;
    int getCombatPower() const override;

//SolareEclipse Functions
    string getDescription() const override;
    void applyCard(Player& Player) const override;
};


class PotionsMerchant : public Event{
public:
//C'tor + big 3
    PotionsMerchant() = default;
    PotionsMerchant(const PotionsMerchant& other) = delete;
    PotionsMerchant& operator=(const PotionsMerchant& other) = delete;
    ~PotionsMerchant() = default;
    int getCombatPower() const override;


    //PotionsMerchant functions
    string getDescription() const override;
    void applyCard(Player& Player) const override;
};

class Encounter : public Card {
public:
//C'tor + big 3
    Encounter(int power, int loot, int damage);
    Encounter(const Encounter&) = delete;
    Encounter& operator=(const Encounter&) = delete;
    virtual ~Encounter() = default;

//Encounter Functions
    virtual string getDescription() const override;
    virtual int getCombatPower() const ;
    int getLoot() const override;
    int getDamage() const override;
    virtual void applyCard(Player& player) const = 0;
    virtual string beastType() const = 0;
protected:
    int m_power;
    int m_loot;
    int m_damage;
};

class Gang : public Encounter {
public:
//C'tor + big 3
    Gang(const Gang& other) = delete;
    Gang(const int power, const int loot, const int damage, const int size);
    Gang& operator=(const Gang& other) = delete;
    ~Gang() = default;

//Gang functions
    void applyCard(Player& player) const override;
    string getDescription() const override;
    string beastType() const override;

private:
    int size;
};

class Goblin : public Encounter {
public:
//C'tor + big 3
    Goblin();
    Goblin(const Goblin& other) = delete;
    Goblin& operator=(const Goblin& other) = delete;
    ~Goblin() = default;

//Goblin functions
    void applyCard(Player& player) const override;
    string beastType() const override;
};

class Giant : public Encounter {
public:
//C'tor + big 3
    Giant();
    Giant(const Giant& other) = delete;
    Giant& operator=(const Giant& other) = delete;
    ~Giant() = default;

//Giant functions
    void applyCard(Player& player) const override;
    string beastType() const override;
};

class Dragon : public Encounter {
public:
//C'tor + big 3
    Dragon();
    Dragon(const Dragon& other) = delete;
    Dragon& operator=(const Dragon& other) = delete;
    ~Dragon() = default;

//Dragon functions
    void applyCard(Player& player) const override;
    string beastType() const override;
};




