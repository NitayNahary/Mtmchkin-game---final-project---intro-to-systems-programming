//
// Created by shach on 6/23/2022.
//

#include "MonsterBehavior.h"

std::ostream& operator<<(std::ostream& os,const MonsterBehavior& monsterBehavior){
    monsterBehavior.printInfo();
    return os;
}
