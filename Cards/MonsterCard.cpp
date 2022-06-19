//
// Created by shach on 6/19/2022.
//

#include "MonsterCard.h"

MonsterCard::MonsterCard(int force, int loot, int damage, bool isDragon) {
    m_force = force;
    m_loot = loot;
    m_damage = damage;
    m_isDragon = isDragon;
}
void MonsterCard::applyEncounter(Player &player) {
    if(player.getAttackStrength() >=m_force){
        applyWin(player);
    }else{
        applyLose(player);
    }
}
bool MonsterCard::applyEncounterGangMembers(Player &player) {
    if(player.getAttackStrength() >=m_force){
        applyWinOnlyLoot(player);
        return true;
    }else{
        applyLose(player);
        return false;
    }
}

bool MonsterCard::isMonster() {
    return true;
}

