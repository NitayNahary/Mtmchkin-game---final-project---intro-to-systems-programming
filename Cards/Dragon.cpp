
#include "Dragon.h"
void Dragon::applyEncounter(Player& player){
    if(player.getAttackStrength() >=m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.name(), "Dragon");
    }
    else
    {
        while(!player.isKnockedOut()){
            player.damage(m_damage);
        }
        printLossBattle(player.name(), "Dragon");
    }
}

void Dragon::printInfo() const {
    printCardDetails(std::cout, "Dragon");
    printMonsterDetails(std::cout, m_force,m_damage, m_loot, m_isDragon);
    printEndOfCardDetails(std::cout);
}

bool Dragon::isMonster() {
    return true;
}
