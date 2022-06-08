
#ifndef HW4_GOBLIN_H
#define HW4_GOBLIN_H
#include "Card.h"

class Goblin : public Card{
public:
    void applyEncounter(Player& player) override;
    void printInfo(std::ostream& os) const override;

private:
    static const int m_force = 6;
    static const int m_loot = 2 ;
    static const int m_damage = 10;
    const bool m_isDragon = false;
};


#endif //HW4_GOBLIN_H
