
#include "CardFactory.h"

std::shared_ptr<Card> createCard(std::string cardName, int lineNumber) {
    if (cardName == "Witch" || cardName == "Witch\r") {
        return std::make_shared<Witch>();
    }
    if (cardName == "Dragon" || cardName == "Dragon\r") {
        return std::make_shared<Dragon>();
    }
    if (cardName == "Gremlin" || cardName == "Gremlin\r") {
        return std::make_shared<Gremlin>();
    }
    if (cardName == "Barfight" || cardName == "Barfight\r") {
        return std::make_shared<Barfight>();
    }
    if (cardName == "Mana" || cardName == "Mana\r") {
        return std::make_shared<Mana>();
    }
    if (cardName == "Well" || cardName == "Well\r") {
        return std::make_shared<Well>();
    }
    if (cardName == "Treasure" || cardName == "Treasure\r") {
        return std::make_shared<Treasure>();
    }
    if (cardName == "Merchant" || cardName == "Merchant\r") {
        return std::make_shared<Merchant>();
    }
    else {
        throw DeckFileFormatError(lineNumber);
    }
}

void createCardQueue (const std::string &fileName, std::queue<std::shared_ptr<Card>>& cardQueue) {
    printStartGameMessage();
    std::ifstream cardFile(fileName);
    if (!cardFile.is_open()){
        throw DeckFileNotFound();
    }
    std::string inputLine;
    int lineCounter = 0; // from the beginning of the file
    while (std ::getline(cardFile,inputLine)){ // as long as you can read from file
        lineCounter++;
        std::shared_ptr<Card> tempCard = createCard(inputLine, lineCounter);
        cardQueue.push(tempCard); // push back new card
    }
    cardFile.close();
    if (cardQueue.size() < MIN_SIZE) {
        throw DeckFileInvalidSize();
    }
}