#include "Treasure.h"

Treasure::Treasure() : Card("Treasure"){}

void Treasure::applyEncounter(std::shared_ptr<Player> player) {
    player->addCoins(COINS_OF_TREASURE);
    printTreasureMessage();
}