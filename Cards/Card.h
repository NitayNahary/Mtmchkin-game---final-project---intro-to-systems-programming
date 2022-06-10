#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include <iostream>
#include "utilities.h"
#include "Players/Player.h"
class Card {
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo(std::ostream& os) const = 0;
public:
    /* Virtual function
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) = 0;

    //operator << prints the players details in this format:
    friend std::ostream& operator<<(std::ostream& os,const Card& card);

    //Default D'tor
    virtual ~Card() = default;
};

#endif //EX4_Card_H