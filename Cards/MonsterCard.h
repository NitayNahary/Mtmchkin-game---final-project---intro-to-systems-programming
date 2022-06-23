
#ifndef HW4_MONSTERCARD_H
#define HW4_MONSTERCARD_H

#include "Card.h"
#include "MonsterBehavior.h"
#include <memory>
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
    MonsterCard(MonsterBehavior* behavior) : Card(), m_cardBehavior(behavior){}

    // Delete Copy C'tor and Assignment operator
    MonsterCard(const MonsterCard& src);
    MonsterCard& operator=(const MonsterCard& src);

    //Default D'tor
    ~MonsterCard() override = default;


    /* Handling the player's applyEncounter with the card:
    *
    * @param player - The player.
    * @return
    *      void
    */
    void applyEncounter(Player& player) const override;

    bool applyEncounterGangMembers(Player& player) const;

    void lose(Player &player) const;

private:
    /*
    * Prints the card info:
    *
    *       @return
    *            void
    */
    void printInfo() const override;
    std::shared_ptr<MonsterBehavior> m_cardBehavior;

};

#endif //HW4_MONSTERCARD_H
