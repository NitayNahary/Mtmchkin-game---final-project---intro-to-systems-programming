
#include "Barfight.h"

Barfight::Barfight() : m_isFighter(false){}

void Barfight::applyEncounter(Player &player){
    m_isFighter = player.getClass() == "Fighter";
    if(!m_isFighter) {
        player.damage(M_EFFECT_VALUE);
    }
    printInfo(std::cout);
}

void Barfight::printInfo(std::ostream& os) const {
    printBarfightMessage(m_isFighter);
}
