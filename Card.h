#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include "utilities.h"
#include "Player.h"
class Card {

public:
    virtual void applyEncounter(Player& player) = 0;
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo(std::ostream& os) const = 0;
    virtual ~Card() = default;
};


std::ostream& operator<<(std::ostream& os,const Card& card);

#endif //EX4_Card_H