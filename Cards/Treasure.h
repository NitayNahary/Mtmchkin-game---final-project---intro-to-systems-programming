
#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H
#include "Card.h"

class Treasure : public Card {
public:
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player &player) override;

private:
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const override;

    static const int M_EFFECT_VALUE = 10;
};


#endif //HW4_TREASURE_H
