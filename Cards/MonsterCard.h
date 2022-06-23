
#ifndef HW4_MONSTERCARD_H
#define HW4_MONSTERCARD_H

#include "Card.h"

class MonsterCard : public Card{
public:
    /*
    * C'tor of MonsterCard card
    *
    *       @param
     *          force - the force of the card
     *          loot - the amount of coins a player gets when wins
     *          damage - the damage to a player losing to the card
     *          isDragon - true/false
    * @return
    *      A new instance of MonsterCard.
    */
    MonsterCard(int force, int loot,int damage, bool isDragon);

    // Delete Copy C'tor and Assignment operator
    MonsterCard(const MonsterCard& src) = delete;
    MonsterCard& operator=(const MonsterCard& src) = delete;

    //Default D'tor
    virtual ~MonsterCard() override = default;

    /*
     * Operates a win sequence on the card
     *
     * @param player - The player.
     * @return
     *      void
    */
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

    /* Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
    */
    void applyEncounter(Player& player) const override;

    /* Handling the player's applyEncounter with the card only with a Gang:
    *
    * @param player - The player.
    * @return
    *      void
    */
    bool applyEncounterGangMembers(Player &player) const;

    //operator << prints the players details in this format:
    friend std::ostream& operator<<(std::ostream& os,const Card& card);

    /*
     * Check if the card is a monster card
     *
     * @return
     *      false
    */
    bool isMonster() const override;

private:
    /*
    * Prints the card info:
    *
    *       @return
    *            void
    */
    virtual void printInfo() const override = 0;
protected:
    int m_force;
    int m_loot;
    int m_damage;
    bool m_isDragon;
};

#endif //HW4_MONSTERCARD_H
