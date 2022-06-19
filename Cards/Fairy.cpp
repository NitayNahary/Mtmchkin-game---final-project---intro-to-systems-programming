
#include "Fairy.h"

Fairy::Fairy() : m_isWizard(false){}

void Fairy::applyEncounter(Player &player){
    m_isWizard = player.getClass() == "Wizard";
    if(m_isWizard){
        player.heal(M_EFFECT_VALUE);
    }
    printFairyMessage(m_isWizard);
}

void Fairy::printInfo() const {
    printCardDetails(std::cout, "Fairy");
    printEndOfCardDetails(std::cout);
}

bool Fairy::isMonster() {
    return false;
}
