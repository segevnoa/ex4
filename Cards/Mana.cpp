#include "Mana.h"


Mana::Mana() : Card("Mana"){}

void Mana:: applyEncounter (std::shared_ptr<Player> player) {
    bool isHealer = false; // not a healer
    std::shared_ptr<Player> tempPlayer = std::dynamic_pointer_cast<Healer>(player);
    if (tempPlayer != NULL) { // it's a healer
        player->heal(HP_OF_MANA);
        isHealer = true;
    }
    printManaMessage(isHealer);
}