
#include "Vampire.h"

void Vampire::applyEncounter(Player& player){
    if(player.getAttackStrength() >=m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.name(), "Vampire");
    }
    else
    {
        player.damage(m_damage);
        player.weaken();
        printLossBattle(player.name(), "Vampire");
    }
}

void Vampire::printInfo() const {
    printCardDetails(std::cout, "Vampire");
    printMonsterDetails(std::cout,m_force,m_damage, m_loot, m_isDragon);
    printEndOfCardDetails(std::cout);
}
