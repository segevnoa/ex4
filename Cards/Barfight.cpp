#include "Barfight.h"

Barfight::Barfight() : Card("Barfight"){}

void Barfight:: applyEncounter(std::shared_ptr<Player> player) {
    bool isWarrior = true;
    std::shared_ptr<Player> tempPlayer = std::dynamic_pointer_cast<Warrior>(player);
    if (tempPlayer == NULL){ // not a warrior
        player->damage(HP_OF_BARFIGHT);
        isWarrior = false;
    }
    printBarfightMessage(isWarrior);
}