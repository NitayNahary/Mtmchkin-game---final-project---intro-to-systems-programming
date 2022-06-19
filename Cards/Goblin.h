
#ifndef HW4_GOBLIN_H
#define HW4_GOBLIN_H
#include "Card.h"
#include "MonsterCard.h"
class Goblin : public MonsterCard{
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
