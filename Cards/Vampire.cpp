
#include "Vampire.h"

void Vampire::printInfo() const {
    printCardDetails(std::cout, "Vampire");
    printMonsterDetails(std::cout,m_force,m_damage, m_loot, m_isDragon);
    printEndOfCardDetails(std::cout);
}

void Vampire::applyWin(Player &player) {
    player.levelUp();
    player.addCoins(m_loot);
    printWinBattle(player.name(), "Vampire");
}

void Vampire::applyLose(Player &player) {
    player.damage(m_damage);
    player.weaken();
    printLossBattle(player.name(), "Vampire");
}

void Vampire::applyWinOnlyLoot(Player &player) {
    player.addCoins(m_loot);
   // printWinBattle(player.name(), "Vampire");
}

