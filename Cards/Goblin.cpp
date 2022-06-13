
#include "Goblin.h"

void Goblin::applyEncounter(Player& player){
    if(player.getAttackStrength() >=m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.name(), "Goblin");
    }
    else
    {
        player.damage(m_damage);
        printLossBattle(player.name(), "Goblin");
    }
}

void Goblin::printInfo() const {
    printMonsterDetails(std::cout,m_force,m_damage, m_loot, m_isDragon);
}
