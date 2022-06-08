#include "Rouge.h"
#include <ostream>


Rouge::Rouge(const std::string name)  : Player(name){}

void Rouge::addCoins(const int coinUp){
    Player::addCoins(2*coinUp);
}

std::string Rouge::getClass() const {
    return "Rouge";
}