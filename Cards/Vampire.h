#ifndef HW4_VAMPIRE_H
#define HW4_VAMPIRE_H

#include "Card.h"
#include "Classes/Player.h"

class Vampire : public Card{
public:
    void applyEncounter(Player& player) override;
    void printInfo() const override = 0;
    ~Vampire() override = default;

private:
    static const int m_force = 10;
    static const int m_loot = 2 ;
    static const int m_damage = 10;
    const bool m_isDragon = false;
};










#endif //HW4_VAMPIRE_H
