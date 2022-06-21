
#include "Dragon.h"

void Dragon::printInfo() const {
    printCardDetails(std::cout, "Dragon");
    printMonsterDetails(std::cout, m_force,m_damage, m_loot, m_isDragon);
    printEndOfCardDetails(std::cout);
}

void Dragon::applyWin(Player &player) const{
    player.levelUp();
    player.addCoins(m_loot);
    printWinBattle(player.name(), "Dragon");
}

void Dragon::applyLose(Player &player) const{
    while(!player.isKnockedOut()){
        player.damage(m_damage);
    }
    printLossBattle(player.name(), "Dragon");
}

void Dragon::applyWinOnlyLoot(Player &player) const{
    player.addCoins(m_loot);
}
