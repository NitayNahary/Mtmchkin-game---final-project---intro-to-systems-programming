
#include "Goblin.h"

void Goblin::applyWin(Player &player) const{
    player.levelUp();
    player.addCoins(m_loot);
    printWinBattle(player.name(), "Goblin");
}

void Goblin::applyWinOnlyLoot(Player &player) const{
    player.addCoins(m_loot);
}

void Goblin::applyLose(Player &player) const{
    player.damage(m_damage);
    printLossBattle(player.name(), "Goblin");
}

void Goblin::printInfo() const {
    printCardDetails(std::cout, "Goblin");
    printMonsterDetails(std::cout,m_force,m_damage, m_loot, m_isDragon);
    printEndOfCardDetails(std::cout);
}
