
#include "Treasure.h"

void Treasure::applyEncounter(Player &player) {
    player.addCoins(M_EFFECT_VALUE);
}

void Treasure::printInfo(std::ostream& os) const {
    printTreasureMessage();
}
