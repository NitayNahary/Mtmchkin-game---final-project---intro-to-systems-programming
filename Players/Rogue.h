
#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H

#include "Player.h"

class Rogue : public Player {
public:
    /***
            Rogue C'tor - Constructs a new Rogue.
                @param name - sets Rogue name
                @return
                    An instance of Rogue
    */
    explicit Rogue(const std::string name);

    //  Copy-Assigment C'tor, Copy C'tor, D'tor - defaulted as string already handles memory, copy and copy-assignment.
    Rogue& operator=(const Rogue& src) = default;
    Rogue(const Rogue& src) = default;
    ~Rogue() override = default;

//--------------------------------------------------------------------------------------------------------------------//

    //add coins to Rogue by coinUp
    void addCoins(const int coinUp) override;

    //@returns Rogue class
    std::string getClass() const override;

};

#endif //HW4_ROGUE_H
