#ifndef MANA_H
#define MANA_H

#include "Card.h"

class Mana : public Card {
public:
    Mana();
    ~Mana() = default;
    void applyEncounter(std::shared_ptr<Player> player) override;

    static const int HP_OF_MANA = 10;
};

#endif //MANA_H
