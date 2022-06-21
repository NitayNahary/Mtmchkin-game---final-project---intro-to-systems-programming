
#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H
#include "Card.h"

class Barfight : public Card{
public:
      /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player &player) const override;
    /*
     * Check if the card is a monster card
     *
     * @return
     *      false
    */
    bool isMonster() const override;
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

#endif //HW4_BARFIGHT_H
