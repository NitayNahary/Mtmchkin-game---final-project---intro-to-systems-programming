#ifndef HW4_DRAGON_H
#define HW4_DRAGON_H
#include "Card.h"
#include "MonsterCard.h"
class Dragon : public MonsterCard{
public:
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyWin(Player& player) override;
    void applyWinOnlyLoot(Player& player) override;
    void applyLose(Player& player) override;
    Dragon() : MonsterCard(25,1000,1000000,true){}
private:

    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const override;

};

#endif //HW4_DRAGON_H
