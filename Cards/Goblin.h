
#ifndef HW4_GOBLIN_H
#define HW4_GOBLIN_H

#include "Card.h"
#include "MonsterBehavior.h"
class Goblin : public MonsterBehavior{
public:
    /*
     * Operates a win sequence on the card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyWin(Player& player) const override;

    /*
     * Applying a win sequence on the card only with loot
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyWinOnlyLoot(Player& player) const override;

    /*
     * Operates a loss sequence on the card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyLose(Player& player) const override;

    int getForce() const override;
private:
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const override;

    static const int M_FORCE = 6;
    static const int M_LOOT = 2;
    static const int M_DAMAGE = 10;
    static const bool M_ISDRAGON = false;
};

#endif //HW4_GOBLIN_H
