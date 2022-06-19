
#include "Goblin.h"

void Goblin::printInfo() const {
    printCardDetails(std::cout, "Goblin");
    printMonsterDetails(std::cout,m_force,m_damage, m_loot, m_isDragon);
    printEndOfCardDetails(std::cout);
}

void Goblin::applyWin(Player &player) {
    player.levelUp();
    player.addCoins(m_loot);
    printWinBattle(player.name(), "Goblin");
}

void Goblin::applyLose(Player &player) {
    player.damage(m_damage);
    printLossBattle(player.name(), "Goblin");
}

void Goblin::applyWinOnlyLoot(Player &player) {
    player.addCoins(m_loot);
    printWinBattle(player.name(), "Goblin");
}
