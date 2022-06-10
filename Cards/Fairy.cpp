
#include "Fairy.h"

void Fairy::applyEncounter(Player &player){
    m_isWizard = player.getClass() == "Wizard";
    if(m_isWizard){
        player.heal(M_EFFECT_VALUE);
    }
    printInfo(std::cout);
}

void Fairy::printInfo(std::ostream& os) const {
    printFairyMessage(m_isWizard);
}
