
#include "Vampire.h"

void Vampire::applyWin(Player &player) const{
    player.levelUp();
    player.addCoins(m_loot);
    printWinBattle(player.name(), "Vampire");
}

void Vampire::applyWinOnlyLoot(Player &player) const{
    player.addCoins(m_loot);
}

void Vampire::applyLose(Player &player) const{
    player.damage(m_damage);
    player.weaken();
    printLossBattle(player.name(), "Vampire");
}

void Vampire::printInfo() const {
    printCardDetails(std::cout, "Vampire");
    printMonsterDetails(std::cout,m_force,m_damage, m_loot, m_isDragon);
    printEndOfCardDetails(std::cout);
}