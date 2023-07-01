#ifndef DRAGON_H
#define DRAGON_H

#include "Battle.h"

class Dragon : public Battle {
public:
    //-- static const for dragon --//
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;
    static const int DRAGON_DAMAGE_INFINITY = 0;
    static const bool IS_DRAGON = true;
    static const bool IS_WITCH = false;

    //-- dragon methods --//
    Dragon ();
    ~Dragon() = default;


};

#endif //DRAGON_H
