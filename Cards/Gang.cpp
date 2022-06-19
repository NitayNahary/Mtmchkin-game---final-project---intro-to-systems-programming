//
// Created by shach on 6/19/2022.
//

#include "Gang.h"

void Gang::printInfo() const{
    for(const std::unique_ptr<MonsterCard>& monster : m_gang){
         Card* monsterCard = static_cast<Card*>(&*monster);
         std::cout << monsterCard << std::endl;
    }
}

void Gang::applyEncounter(Player &player) {
    bool lostOnce = false;
    for(int i = 0; i < m_gang.size(); i++){
        if(!lostOnce) {
            if (!m_gang[i]->applyEncounterGangMembers(player)) {
                lostOnce = true;
            }
        }else{
            m_gang[i]->applyLose(player);
        }
    }
}

void Gang::pushBack(std::unique_ptr<Card> addToGang) {
    Card* rawGangMemeber = addToGang.release();
    MonsterCard* monster = static_cast<MonsterCard*>(rawGangMemeber);
    m_gang.push_back(std::unique_ptr<MonsterCard>(monster));
}

bool Gang::open() const {
    return m_open;
}

Gang::Gang() {
    m_open = true;
}

void Gang::close(){
    m_open = false;
}

bool Gang::isMonster() {
    return false;
}
