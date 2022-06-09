#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include <iostream>
#include "utilities.h"
#include "Players/Player.h"
class Card {
    virtual void printInfo(std::ostream& os) const = 0;
public:
    virtual void applyEncounter(Player& player) = 0;
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    friend std::ostream& operator<<(std::ostream& os,const Card& card);
    virtual ~Card() = default;
};




#endif //EX4_Card_H