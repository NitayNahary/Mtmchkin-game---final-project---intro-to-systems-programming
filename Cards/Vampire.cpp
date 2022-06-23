
#include "Vampire.h"

static const std::string M_NAME = "Vampire";

void Vampire::applyWin(Player &player) const{
    player.levelUp();
    player.addCoins(M_LOOT);
    printWinBattle(player.name(), M_NAME);
}

void Vampire::applyWinOnlyLoot(Player &player) const{
    player.addCoins(M_LOOT);
}

void Vampire::applyLose(Player &player) const{
    player.damage(M_DAMAGE);
    player.weaken();
    printLossBattle(player.name(), M_NAME);
}

void Vampire::printInfo() const {
    printCardDetails(std::cout, M_NAME);
    printMonsterDetails(std::cout,M_FORCE,M_DAMAGE, M_LOOT, M_ISDRAGON);
    printEndOfCardDetails(std::cout);
}

int Vampire::getForce() const {
    return M_FORCE;
}
