#include "Wizard.h"
#include <ostream>


Wizard::Wizard(const std::string name)  : Player(name){}

void Wizard::heal(const int hpUp){
    Player::heal(2*hpUp);
}

std::string Wizard::getClass() const {
    return "Wizard";
}