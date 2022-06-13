
#include "Barfight.h"

Barfight::Barfight() : m_isFighter(false){}

void Barfight::applyEncounter(Player &player){
    m_isFighter = player.getClass() == "Fighter";
    if(!m_isFighter) {
        player.damage(M_EFFECT_VALUE);
    }
    printInfo();
}

void Barfight::printInfo() const {
    printBarfightMessage(m_isFighter);
}
