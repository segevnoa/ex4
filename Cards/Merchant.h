#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"

class Merchant : public Card {
public:
    Merchant();
    ~Merchant() = default;
    void applyEncounter(std::shared_ptr<Player> player) override;

    static const int FIRST_INPUT = 0;
    static const int SECOND_INPUT = 1;
    static const int THIRD_INPUT = 2;
    static const int GAINED_HP = 1;
    static const int PAY_HP = 5;
    static const int PAY_FORCE = 10;
};

#endif //MERCHANT_H
