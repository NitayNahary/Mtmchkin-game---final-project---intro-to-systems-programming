
#include "Treasure.h"

void Treasure::applyEncounter(Player &player) {
    player.addCoins(M_EFFECT_VALUE);
    printInfo(std::cout);
}

void Treasure::printInfo(std::ostream& os) const {
    printTreasureMessage();
}
