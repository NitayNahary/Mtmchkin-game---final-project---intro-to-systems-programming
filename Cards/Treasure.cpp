
#include "Treasure.h"

void Treasure::applyEncounter(Player &player) const{
    player.addCoins(M_EFFECT_VALUE);
    printTreasureMessage();
}

void Treasure::printInfo() const {
    printCardDetails(std::cout, "Treasure");
    printEndOfCardDetails(std::cout);
}

bool Treasure::isMonster() const{
    return false;
}
