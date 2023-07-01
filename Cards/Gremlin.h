#ifndef GREMLIN_H
#define GREMLIN_H

#include "Battle.h"

class Gremlin : public Battle {
public:
    //-- static const for gremlin --//
    static const int GREMLIN_FORCE = 5;
    static const int GREMLIN_LOOT = 2;
    static const int GREMLIN_DAMAGE = 10;
    static const bool IS_DRAGON = false;
    static const bool IS_WITCH = false;

    //-- gremlin methods --//
    Gremlin ();
    ~Gremlin() = default;
};

#endif //GREMLIN_H
