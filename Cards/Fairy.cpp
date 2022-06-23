
#include "Fairy.h"

void Fairy::applyEncounter(Player &player) const{
    bool isWizard = player.getClass() == "Wizard";
    if(isWizard){
        player.heal(M_EFFECT_VALUE);
    }
    printFairyMessage(isWizard);
}

bool Fairy::isMonster() const{
    return false;
}

void Fairy::printInfo() const {
    printCardDetails(std::cout, "Fairy");
    printEndOfCardDetails(std::cout);
}