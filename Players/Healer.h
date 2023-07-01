#ifndef HEALER_H
#define HEALER_H

#include "utilities.h"
#include "Player.h"

class Healer : public Player {
public:
    //-- healer methods --//
    Healer(std::string playerName);
    void heal (int moreHP) override;
};

#endif //HEALER_H
