
#ifndef HW4_GOBLIN_H
#define HW4_GOBLIN_H
#include "Cards/nonBattleMonsters/Card.h"

class Goblin : public Card{
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
    void printInfo(std::ostream& os) const override;

    static const int m_force = 6;
    static const int m_loot = 2 ;
    static const int m_damage = 10;
    const bool m_isDragon = false;
};


#endif //HW4_GOBLIN_H
