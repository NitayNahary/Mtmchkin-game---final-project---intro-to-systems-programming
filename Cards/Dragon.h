#ifndef HW4_DRAGON_H
#define HW4_DRAGON_H
#include "Card.h"
#include "MonsterCard.h"
class Dragon : public MonsterCard{
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
    * Empty C'tor of Dragon card
    *
    *       @param
     *          MonsterCard C'tor initialized with:
     *          force - the force of the card
     *          loot - the amount of coins a player gets when wins
     *          damage - the damage to a player losing to this card - infinite
     *          isDragon - true
    * @return
    *      A new instance of Dragon.
    */
    Dragon() : MonsterCard(M_FORCE,M_LOOT,M_DAMAGE,M_ISDRAGON){}
    Dragon(const Dragon& src) : MonsterCard(M_FORCE,M_LOOT,M_DAMAGE,M_ISDRAGON){}
    Dragon& operator=(const Dragon& src){return *this;}
    ~Dragon() override = default;
private:

    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const override;
    static const int M_FORCE = 25;
    static const int M_LOOT = 1000;
    static const int M_DAMAGE = 1000000;
    static const bool M_ISDRAGON = true;
};

#endif //HW4_DRAGON_H
