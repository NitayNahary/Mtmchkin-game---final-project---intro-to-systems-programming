
#include "Barfight.h"

void Barfight::applyEncounter(Player &player){
    m_isFighter = player.getClass() == "Fighter";
    if(!m_isFighter)
        player.damage(M_EFFECT_VALUE);
}

void Barfight::printInfo(std::ostream& os) const {
    printBarfightMessage(m_isFighter);
}
