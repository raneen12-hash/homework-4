
#pragma once

#include <string>
#include <memory>
#include <vector>
#include <queue>

#include "Players/Player.h"
#include "Event/Event.h"
#include "Exception.h"
#include <fstream>
#include <sstream>


using std::string;
using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::queue;

class Mtmchkin{
private:
    int m_turnIndex;
    vector<unique_ptr<Player>> m_players;
    vector<unique_ptr<Card>> m_cards;
    Gang* makeGang(string *arr, int begin, int end);
    void cardmake(const string& Path);
    void playermake(const string& Path);

    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

public:
    /**
     * Constructor of Mtmchkin class
     *
     * @param deckPath - path to the deck file
     * @param playersPath - path to the players file
     *
     * @return - Mtmchkin object with the given deck and players
     *
    */
    Mtmchkin(const string& deckPath, const string& playersPath);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();


    /**
     * sorts the m_players vector according to level/coins/lexicographic order of names
     *
     * @return - void
    */
    void mtmSort(vector<Player*>* temp);

    void Aux_func(string *arr, int j, int &size, int &flag, int &s, int &temp_power, int &temp_damage, int &temp_loot,int& flag_k );

    void
    Aux_lesslines(string *arr, int j, int &size, int &flag, int &s, int &temp_power, int &temp_damage, int &temp_loot,
                  int &flag_k, int &k);
};






pragma once

#include <iostream>

#include "Players/Player.h"
#include "Events/Event.h"


class MatamStory{
private:
    unsigned int m_turnIndex;

    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

public:
    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();
};