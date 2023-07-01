#ifndef WARRIOR_H
#define WARRIOR_H

#include "utilities.h"
#include "Player.h"

class Warrior : public Player {
public:
    //-- warrior methods --//
    Warrior(std::string playerName);
    int getAttackForce () override;
};

#endif //WARRIOR_H
