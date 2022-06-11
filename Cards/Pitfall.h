
#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H
#include "Card.h"

class Pitfall : public Card{
public:

    Pitfall();
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
    void printInfo(std::ostream& os) const override;

    static const int M_EFFECT_VALUE = 10;
    bool m_isRogue;
};


#endif //HW4_PITFALL_H
