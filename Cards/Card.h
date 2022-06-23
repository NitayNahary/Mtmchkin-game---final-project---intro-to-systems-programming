
#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include <iostream>
#include "../MyUtilities.h"
#include "../Players/Player.h"

class Card {
public:
    //Default C'tor, Copt C'tor, Assignment operator
    Card() = default;
    Card(const Card& src) = default;
    Card& operator=(const Card& src) = default;

    //Default D'tor
    virtual ~Card() = default;

    /* Virtual function
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;

    //operator << prints the card details
    friend std::ostream& operator<<(std::ostream& os,const Card& card);

private:
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo() const = 0;
};

#endif //EX4_Card_H