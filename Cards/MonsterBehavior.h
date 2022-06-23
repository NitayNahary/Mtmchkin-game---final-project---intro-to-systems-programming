//
// Created by shach on 6/23/2022.
//

#ifndef HW4_MONSTERBEHAVIOR_H
#define HW4_MONSTERBEHAVIOR_H


#include <string>
#include "../Players/Player.h"

class MonsterBehavior {
public:
    /*
     * Operates a win sequence on the card
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual int getForce() const = 0;

    virtual void applyWin(Player& player) const = 0;

    /*
     * Applying a win sequence on the card only with loot
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyWinOnlyLoot(Player& player) const = 0;

    /*
     * Operates a loss sequence on the card
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyLose(Player& player) const = 0;

    /*
    * Empty C'tor of Vampire card
    *
    *       @param
     *          MonsterCard C'tor initialized with:
     *          force - the force of the card
     *          loot - the amount of coins a player gets when wins
     *          damage - the damage to a player losing to this card
     *          isDragon - false
    * @return
    *      A new instance of Vampire.
    */
    friend std::ostream& operator<<(std::ostream& os,const MonsterBehavior& monsterBehavior);

    MonsterBehavior() = default;
    MonsterBehavior(const MonsterBehavior& src) = default;
    MonsterBehavior& operator=(const MonsterBehavior& src) = default;

    //Default D'tor
    virtual ~MonsterBehavior() = default;

private:
    virtual void printInfo() const = 0;
};


#endif //HW4_MONSTERBEHAVIOR_H
