
#include "Barfight.h"

void Barfight::applyEncounter(Player &player) const{
    bool isFighter = player.getClass() == "Fighter";
    if(!isFighter) {
        player.damage(M_EFFECT_VALUE);
    }
    printBarfightMessage(isFighter);
}

bool Barfight::isMonster() const{
    return false;
}

void Barfight::printInfo() const {
    printCardDetails(std::cout, "Barfight");
    printEndOfCardDetails(std::cout);
}