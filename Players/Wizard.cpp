#include "Wizard.h"
#include <ostream>


Wizard::Wizard(const char* name)  : Player(name){}

void Wizard::heal(const int hpUp){
    Player::heal(2*hpUp);
}

string Wizard::getClass() const {
    return "Wizard";
}