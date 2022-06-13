
#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H
#include "Card.h"

class Barfight : public Card{
public:
    Barfight();
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
    bool m_isFighter;
};

#endif //HW4_BARFIGHT_H
