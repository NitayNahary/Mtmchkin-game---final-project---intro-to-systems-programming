
#include "Gang.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Vampire.h"

Gang::Gang() {
    m_open = true;
}

Gang::Gang(const Gang &src) : Card() , m_open(src.m_open), m_gang(){
    for(const std::unique_ptr<MonsterCard>& monster : src.m_gang) {
        m_gang.push_back(std::unique_ptr<MonsterCard>(new MonsterCard(*monster)));
    }
}

Gang &Gang::operator=(const Gang &src) {
    if(src.m_gang == m_gang && src.m_open == m_open){
        return *this;
    }
    std::deque<std::unique_ptr<MonsterCard>> temp_gang;
    for(const std::unique_ptr<MonsterCard>& monster : src.m_gang){
        temp_gang.push_back(std::unique_ptr<MonsterCard>(new MonsterCard(*monster)));
    }
    std::swap(m_gang, temp_gang);
    m_open = src.m_open;
    return  *this;
}

void Gang::applyEncounter(Player &player) const{
    bool unDefeated = true;
    for(const std::unique_ptr<MonsterCard>& monster : m_gang){
        if(unDefeated) {
            if (!monster->applyEncounterGangMembers(player)) {
                unDefeated = false;
            }
        }else{
            monster->lose(player);
        }
    }
    if(unDefeated){
        player.levelUp();
        printWinBattle(player.name(), "Gang");
    }
}

void Gang::pushBack(std::unique_ptr<MonsterCard> addToGang) {
    m_gang.push_back(std::move(addToGang));
}

bool Gang::open() const {
    return m_open;
}

void Gang::close(){
    m_open = false;
}

void Gang::printInfo() const{
    std::cout<< "Gang:" << std::endl;
    std::cout<< "-------------------------------" <<std::endl;
    for(const std::unique_ptr<MonsterCard>& monster : m_gang){
        std::cout << *monster << std::endl;
    }
    if(!m_open) {
        std::cout << "End Of Gang" << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }else{
        std::cout << "Still Open For More Monsters - Call 1-800-800-3" << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }
}
