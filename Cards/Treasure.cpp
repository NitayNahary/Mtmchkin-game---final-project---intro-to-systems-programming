
#include "Treasure.h"

void Treasure::applyEncounter(Player &player) {
    player.addCoins(M_EFFECT_VALUE);
    printInfo();
}

void Treasure::printInfo() const {
    printTreasureMessage();
}
