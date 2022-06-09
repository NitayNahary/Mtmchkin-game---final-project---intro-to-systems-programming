#ifndef HW4_VAMPIRE_H
#define HW4_VAMPIRE_H
#include "Cards/nonBattleMonsters/Card.h"

class Vampire : public Card{
public:
    void applyEncounter(Player& player) override;
    ~Vampire() override = default;

private:
    void printInfo(std::ostream& os) const override;
    static const int m_force = 10;
    static const int m_loot = 2 ;
    static const int m_damage = 10;
    const bool m_isDragon = false;
};










#endif //HW4_VAMPIRE_H
