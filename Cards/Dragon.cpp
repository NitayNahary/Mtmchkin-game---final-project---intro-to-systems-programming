
#include "Dragon.h"

void Dragon::applyWin(Player &player) const{
    player.levelUp();
    player.addCoins(M_LOOT);
    printWinBattle(player.name(), "Dragon");
}

void Dragon::applyWinOnlyLoot(Player &player) const{
    player.addCoins(M_LOOT);
}

void Dragon::applyLose(Player &player) const{
    while(!player.isKnockedOut()){
        player.damage(M_DAMAGE);
    }
    printLossBattle(player.name(), "Dragon");
}

void Dragon::printInfo() const {
    printCardDetails(std::cout, "Dragon");
    printMonsterDetails(std::cout, M_FORCE,M_DAMAGE, M_LOOT, M_ISDRAGON);
    printEndOfCardDetails(std::cout);
}

int Dragon::getForce() const {
    return M_FORCE;
}
