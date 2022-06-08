
#include "Vampire.h"

void Vampire::applyEncounter(Player& player){
    if(player.getAttackStrength() >=m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Vampire");
    }
    else
    {
        player.damage(m_damage);
        player.weaken();
        printLossBattle(player.getName(), "Vampire");
    }
}

void Vampire::printInfo() const {
    printMonsterDetails(std::cout,m_force,m_damage, m_loot, m_isDragon);
}
