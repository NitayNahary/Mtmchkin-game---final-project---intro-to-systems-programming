#ifndef HW4_WIZARD_H
#define HW4_WIZARD_H

#include "Player.h"


class Wizard : public Player {
public:
    explicit Wizard(const char* name);
    Wizard& operator=(const Wizard& src) = default;
    Wizard(const Wizard& src) = default;
    ~Wizard() override = default;

//--------------------------------------------------------------------------------------------------------------------//
    void heal(const int hpUp) override;
    string getClass() const override;

};

#endif //HW4_WIZARD_H
