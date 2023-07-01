#ifndef NINJA_H
#define NINJA_H

#include "utilities.h"
#include "Player.h"

class Ninja : public Player {
public:
    //-- ninja methods --//
    Ninja(std::string playerName);
    void addCoins (int moreCoins) override;
};

#endif //NINJA_H
