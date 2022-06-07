
#include "Goblin.h"

void Goblin::applyEncounter(Player& player){
    if(player.getAttackStrength() >=m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Goblin");
    }
    else
    {
        player.damage(m_damage);
        printLossBattle(player.getName(), "Goblin");
    }
}

void Goblin::printInfo(std::ostream& os) const {
    printMonsterDetails(os,m_force,m_damage, m_loot, m_isDragon);
}
