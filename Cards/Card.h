#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include <iostream>
#include "../MyUtilities.h"
#include "../Players/Player.h"
class Card {
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo() const = 0;
public:
    /* Virtual function
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) = 0;

    /*
     * Check if the card is a monster card
     *
     * @return
     *      bool - true/false
    */
    virtual bool isMonster() = 0;

    //operator << prints the players details in this format:
    friend std::ostream& operator<<(std::ostream& os,const Card& card);

    //Default D'tor
    virtual ~Card() = default;
};

#endif //EX4_Card_H