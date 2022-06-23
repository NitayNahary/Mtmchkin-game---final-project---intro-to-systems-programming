
#include "MonsterCard.h"

void MonsterCard::applyEncounter(Player &player) const{
    if(player.getAttackStrength() >= m_cardBehavior->getForce()){
        m_cardBehavior->applyWin(player);
    }else{
        m_cardBehavior->applyLose(player);
    }
}

void MonsterCard::printInfo() const {
    std::cout << *m_cardBehavior << std::endl;
}

bool MonsterCard::applyEncounterGangMembers(Player &player) const{
    if(player.getAttackStrength() >= m_cardBehavior->getForce()){
        m_cardBehavior->applyWinOnlyLoot(player);
        return true;
    }else{
        m_cardBehavior->applyLose(player);
        return false;
    }
}

MonsterCard::MonsterCard(const MonsterCard &src) : Card(), m_cardBehavior(src.m_cardBehavior) {
}

MonsterCard &MonsterCard::operator=(const MonsterCard &src){
    if(this == &src) return *this;
    m_cardBehavior.reset();
    m_cardBehavior = src.m_cardBehavior;
    return *this;
}

void MonsterCard::lose(Player &player) const {
    m_cardBehavior->applyLose(player);
}

