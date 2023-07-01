#ifndef CARD_H
#define CARD_H

#include "utilities.h"
#include <iostream>
#include "Players/Player.h"
#include "Players/Healer.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"

class Card {
public:
    //-- constructors --//
    Card () = default;
    Card (std::string cardName);
    Card(const Card&) = default;
    virtual ~Card()= default;
    Card& operator=(const Card& other) = default;
    //-- methods --//
    std::string getName();
    virtual void applyEncounter(std::shared_ptr<Player> player) = 0;
    virtual std::ostream& printCardInfo(std::ostream& os) const;
protected:
    std::string m_cardName;
private:
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

};


#endif //CARD_H
