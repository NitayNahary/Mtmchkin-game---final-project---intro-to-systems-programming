
#include "MonsterCard.h"

MonsterCard::MonsterCard(int force, int loot, int damage, bool isDragon) {
    m_force = force;
    m_loot = loot;
    m_damage = damage;
    m_isDragon = isDragon;
}
void MonsterCard::applyEncounter(Player &player) const{
    if(player.getAttackStrength() >=m_force){
        applyWin(player);
    }else{
        applyLose(player);
    }
}
bool MonsterCard::applyEncounterGangMembers(Player &player) const{
    if(player.getAttackStrength() >=m_force){
        applyWinOnlyLoot(player);
        return true;
    }else{
        applyLose(player);
        return false;
    }
}

bool MonsterCard::isMonster() const{
    return true;
}

