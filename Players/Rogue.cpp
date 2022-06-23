
#include "Rogue.h"
#include <ostream>


Rogue::Rogue(const std::string name)  : Player(name){}

void Rogue::addCoins(const int coinUp){
    Player::addCoins(2*coinUp);
}

std::string Rogue::getClass() const {
    return "Rogue";
}