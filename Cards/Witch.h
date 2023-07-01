#ifndef WITCH_H
#define WITCH_H

#include "Battle.h"

class Witch : public Battle {
public:
    //-- static const for witch  --//
    static const int WITCH_FORCE = 11;
    static const int WITCH_LOOT = 2;
    static const int WITCH_DAMAGE = 10;
    static const bool IS_DRAGON = false;
    static const bool IS_WITCH = true;

    //-- witch methods --//
    Witch () ;
    ~Witch() = default;
};

#endif //WITCH_H
