
#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H
#include "Card.h"

class Fairy : public Card {
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


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
private:
    void printInfo(std::ostream& os) const override;
    static const int M_EFFECT_VALUE = 10;
    bool m_isWizard;
};

#endif //HW4_FAIRY_H
