#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H

#include "Player.h"


class Fighter : public Player {
public:
    /***
            Fighter C'tor - Constructs a new Fighter.
                @param name - sets Fighter name
                @return
                    An instance of Fighter
    */
    explicit Fighter(const  std::string name);

    //  Copy-Assigment C'tor, Copy C'tor, D'tor - defaulted as string already handles memory, copy and copy-assignment.
    Fighter& operator=(const Fighter& src) = default;
    Fighter(const Fighter& src) = default;
    ~Fighter() override = default;

//--------------------------------------------------------------------------------------------------------------------//

    //@returns Fighter attack strength
    int getAttackStrength() const override;

    //@returns Fighter class
    std::string getClass() const override;

};






#endif //HW4_FIGHTER_H
