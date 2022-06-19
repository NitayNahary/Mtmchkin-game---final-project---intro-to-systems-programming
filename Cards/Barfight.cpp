
#include "Barfight.h"

Barfight::Barfight() : m_isFighter(false){}

void Barfight::applyEncounter(Player &player){
    m_isFighter = player.getClass() == "Fighter";
    if(!m_isFighter) {
        player.damage(M_EFFECT_VALUE);
    }
    printBarfightMessage(m_isFighter);
}

void Barfight::printInfo() const {
    printCardDetails(std::cout, "Barfight");
    printEndOfCardDetails(std::cout);
}

bool Barfight::isMonster() {
    return false;
}
