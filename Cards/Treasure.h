#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    Treasure();
    ~Treasure() = default;
    void applyEncounter(std::shared_ptr<Player> player) override;

    static const int COINS_OF_TREASURE = 10;
};

#endif //TREASURE_H
