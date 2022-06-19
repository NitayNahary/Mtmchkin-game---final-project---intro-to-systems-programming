//
// Created by shach on 6/19/2022.
//

#ifndef HW4_MONSTERCARD_H
#define HW4_MONSTERCARD_H
#include "Card.h"

class MonsterCard : public Card{
    virtual void printInfo() const override = 0;
protected:
    int m_force;
    int m_loot;
    int m_damage;
    bool m_isDragon;
public:
    MonsterCard(int force, int loot,int damage, bool isDragon);
    virtual void applyWin(Player& player) = 0;
    virtual void applyWinOnlyLoot(Player& player) = 0;
    virtual void applyLose(Player& player) = 0;
    void applyEncounter(Player& player) override;
    bool applyEncounterGangMembers(Player &player);
    friend std::ostream& operator<<(std::ostream& os,const Card& card);
    bool isMonster() override;
    virtual ~MonsterCard() override = default;
};


#endif //HW4_MONSTERCARD_H
