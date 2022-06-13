
#include "Fairy.h"

Fairy::Fairy() : m_isWizard(false){}

void Fairy::applyEncounter(Player &player){
    m_isWizard = player.getClass() == "Wizard";
    if(m_isWizard){
        player.heal(M_EFFECT_VALUE);
    }
    printInfo();
}

void Fairy::printInfo() const {
    printFairyMessage(m_isWizard);
}
