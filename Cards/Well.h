#ifndef WELL_H
#define WELL_H

#include "Card.h"

class Well : public Card {
public:
     Well();
    void applyEncounter(std::shared_ptr<Player> player) override;

    static const int HP_OF_WELL = 10;
};

#endif //WELL_H
