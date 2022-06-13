#ifndef HW4_DRAGON_H
#define HW4_DRAGON_H
#include "Card.h"

class Dragon : public Card{
public:
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) override;

private:
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const override;

    static const int m_force = 25;
    static const int m_loot = 1000 ;
    static const int m_damage = 1000000;
    const bool m_isDragon = true;
};

#endif //HW4_DRAGON_H
