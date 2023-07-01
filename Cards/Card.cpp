#include "Card.h"

Card::Card (std::string cardName):
        m_cardName(cardName){}

std::string Card::getName(){
    return m_cardName;
}

std::ostream& Card::printCardInfo(std::ostream& os) const {
    std::string name = m_cardName;
    printCardDetails(os, name);
    printEndOfCardDetails(os);
    return os;
}

std::ostream& operator<<(std::ostream& os, const Card& card){
    return card.printCardInfo(os);
}


