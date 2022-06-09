#ifndef HW4_WIZARD_H
#define HW4_WIZARD_H

#include "Player.h"


class Wizard : public Player {
public:
    /***
            Wizard C'tor - Constructs a new Wizard.
                @param name - sets Wizard name
                @return
                    An instance of Wizard
    */
    explicit Wizard(const std::string name);

    //  Copy-Assigment C'tor, Copy C'tor, D'tor - defaulted as string already handles memory, copy and copy-assignment.
    Wizard& operator=(const Wizard& src) = default;
    Wizard(const Wizard& src) = default;
    ~Wizard() override = default;

//--------------------------------------------------------------------------------------------------------------------//

    //increase Wizard's hp by hpUp
    void heal(const int hpUp) override;

    //@returns Wizard class
    std::string getClass() const override;

};

#endif //HW4_WIZARD_H
