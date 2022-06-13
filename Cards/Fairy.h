
#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H
#include "Card.h"

class Fairy : public Card {
public:
    Fairy();
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
    bool m_isWizard;
};

#endif //HW4_FAIRY_H
