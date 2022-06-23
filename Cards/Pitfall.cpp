
#include "Pitfall.h"

void Pitfall::applyEncounter(Player &player) const{
    bool isRogue = player.getClass() == "Rogue";
    if(!isRogue) {
        player.damage(M_EFFECT_VALUE);
    }
    printPitfallMessage(isRogue);
}

bool Pitfall::isMonster() const{
    return false;
}

void Pitfall::printInfo() const {
    printCardDetails(std::cout, "Pitfall");
    printEndOfCardDetails(std::cout);
}