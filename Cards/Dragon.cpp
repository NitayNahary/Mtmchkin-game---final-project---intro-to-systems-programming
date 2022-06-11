
#include "Dragon.h"
void Dragon::applyEncounter(Player& player){
    if(player.getAttackStrength() >=m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Dragon");
    }
    else
    {
        while(!player.isKnockedOut()){
            player.damage(m_damage);
        }
        printLossBattle(player.getName(), "Dragon");
    }
}

void Dragon::printInfo(std::ostream& os) const {
    printMonsterDetails(os, m_force,m_damage, m_loot, m_isDragon);
}