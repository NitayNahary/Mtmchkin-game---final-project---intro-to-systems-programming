#include "Card.h"
#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H


class Barfight : public Card{
public:
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player &player) override;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo(std::ostream& os) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
private:
    static const int M_EFFECT_VALUE = 10;
    bool m_isFighter;
};

#endif //HW4_BARFIGHT_H
