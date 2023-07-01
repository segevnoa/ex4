#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
     Barfight();
    ~Barfight() = default;
    void applyEncounter(std::shared_ptr<Player> player) override;

    static const int HP_OF_BARFIGHT = 10;
};

#endif //BARFIGHT_H
