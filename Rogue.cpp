#include "Rouge.h"
#include <ostream>


Rouge::Rouge(const char *name)  : Player(name){}

void Rouge::addCoins(const int coinUp){
    Player::addCoins(2*coinUp);
}

string Rouge::getClass() const {
    return "Rouge";
}