#ifndef HW4_VAMPIRE_H
#define HW4_VAMPIRE_H
#include "Card.h"

class Vampire : public Card{
public:
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) override;
    bool isMonster() override;
private:
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const override;

    static const int m_force = 10;
    static const int m_loot = 2 ;
    static const int m_damage = 10;
    const bool m_isDragon = false;
};










#endif //HW4_VAMPIRE_H
