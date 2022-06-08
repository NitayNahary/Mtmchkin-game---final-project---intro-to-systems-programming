#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H

#include "Player.h"


class Fighter : public Player {
public:
    explicit Fighter(const  std::string name);
    Fighter& operator=(const Fighter& src) = default;
    Fighter(const Fighter& src) = default;
    ~Fighter() override = default;

//--------------------------------------------------------------------------------------------------------------------//
    int getAttackStrength() const override;
    std::string getClass() const override;

};






#endif //HW4_FIGHTER_H