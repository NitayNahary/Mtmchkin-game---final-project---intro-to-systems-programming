#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H


#include "Player.h"

class Rogue : public Player {
public:
    explicit Rogue(const std::string name);
    Rogue& operator=(const Rogue& src) = default;
    Rogue(const Rogue& src) = default;
    ~Rogue() override = default;

//--------------------------------------------------------------------------------------------------------------------//
    void addCoins(const int coinUp) override;
    std::string getClass() const override;

};

#endif //HW4_ROGUE_H
