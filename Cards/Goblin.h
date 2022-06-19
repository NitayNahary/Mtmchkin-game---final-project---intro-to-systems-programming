
#ifndef HW4_GOBLIN_H
#define HW4_GOBLIN_H
#include "Card.h"
#include "MonsterCard.h"
class Goblin : public MonsterCard{
public:
    /*
     * Operates a win sequence on the card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyWin(Player& player) override;

    /*
     * Applying a win sequence on the card only with loot
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyWinOnlyLoot(Player& player) override;

    /*
     * Operates a loss sequence on the card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyLose(Player& player) override;

    /*
    * Empty C'tor of Goblin card
    *
    *       @param
     *          MonsterCard C'tor initialized with:
     *          force - the force of the card
     *          loot - the amount of coins a player gets when wins
     *          damage - the damage to a player losing to this card
     *          isDragon - false
    * @return
    *      A new instance of Goblin.
    */
    Goblin() : MonsterCard(6,2,10,false){}
private:

    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const override;

};


#endif //HW4_GOBLIN_H
