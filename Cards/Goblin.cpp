
#include "Goblin.h"

void Goblin::applyWin(Player &player) const{
    player.levelUp();
    player.addCoins(M_LOOT);
    printWinBattle(player.name(), "Goblin");
}

void Goblin::applyWinOnlyLoot(Player &player) const{
    player.addCoins(M_LOOT);
}

void Goblin::applyLose(Player &player) const{
    player.damage(M_DAMAGE);
    printLossBattle(player.name(), "Goblin");
}

void Goblin::printInfo() const {
    printCardDetails(std::cout, "Goblin");
    printMonsterDetails(std::cout,M_FORCE,M_DAMAGE, M_LOOT, M_ISDRAGON);
    printEndOfCardDetails(std::cout);
}

int Goblin::getForce() const {
    return M_FORCE;
}
