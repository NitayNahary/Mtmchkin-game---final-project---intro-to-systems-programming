//
// Created by shach on 6/19/2022.
//

#include "Gang.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Vampire.h"

void Gang::printInfo() const{
    for(const std::unique_ptr<MonsterCard>& monster : m_gang){
         Card* monsterCard = static_cast<Card*>(&*monster);
         std::cout << monsterCard << std::endl;
    }
    std::cerr<< "GangBANG" <<std::endl;
}

void Gang::applyEncounter(Player &player) const{
    bool lostOnce = false;
    for(const std::unique_ptr<MonsterCard>& monster : m_gang){
        if(!lostOnce) {
            if (!monster->applyEncounterGangMembers(player)) {
                lostOnce = true;
            }
        }else{
            monster->applyLose(player);
        }
    }
    if(!lostOnce){
        player.levelUp();
        printWinBattle(player.name(), "Gang");
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

bool Gang::isMonster() const{
    return false;
}

Gang::Gang(const Gang &src) : Card() , m_open(src.m_open){
    for(const std::unique_ptr<MonsterCard>& monster : src.m_gang){
        if(dynamic_cast<Dragon*>(&*monster)){
            m_gang.push_back(std::unique_ptr<MonsterCard>(new Dragon()));
        }else if(dynamic_cast<Goblin*>(&*monster)){
            m_gang.push_back(std::unique_ptr<MonsterCard>(new Goblin()));
        }else if(dynamic_cast<Vampire*>(&*monster)){
            m_gang.push_back(std::unique_ptr<MonsterCard>(new Vampire()));
        }
    }
}

Gang &Gang::operator=(const Gang &src) {
    if(src.m_gang == m_gang && src.m_open == m_open){
        return *this;
    }
    std::deque<std::unique_ptr<MonsterCard>> temp_gang;
    for(const std::unique_ptr<MonsterCard>& monster : src.m_gang){
        if(dynamic_cast<Dragon*>(&*monster)){
            temp_gang.push_back(std::unique_ptr<MonsterCard>(new Dragon()));
        }else if(dynamic_cast<Goblin*>(&*monster)){
            temp_gang.push_back(std::unique_ptr<MonsterCard>(new Goblin()));
        }else if(dynamic_cast<Vampire*>(&*monster)){
            temp_gang.push_back(std::unique_ptr<MonsterCard>(new Vampire()));
        }
    }
    std::swap(m_gang, temp_gang);
    m_open = src.m_open;
    return  *this;
}
