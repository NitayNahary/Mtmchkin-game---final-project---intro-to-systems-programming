
#ifndef HW4_VAMPIRE_H
#define HW4_VAMPIRE_H

#include "Card.h"
#include "MonsterCard.h"

class Vampire : public MonsterCard{
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
    Vampire() : MonsterCard(M_FORCE,M_LOOT,M_DAMAGE,M_ISDRAGON){}

    // Copy C'tor, Assignment operator and Default D'tor of Vampire card
    Vampire(const Vampire& src) : MonsterCard(M_FORCE,M_LOOT,M_DAMAGE,M_ISDRAGON){}
    Vampire& operator=(const Vampire& src){return *this;}
    ~Vampire() override = default;
private:
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const override;

    static const int M_FORCE = 10;
    static const int M_LOOT = 2;
    static const int M_DAMAGE = 10;
    static const bool M_ISDRAGON = false;
};










#endif //HW4_VAMPIRE_H
