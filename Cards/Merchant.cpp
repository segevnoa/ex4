#include "Merchant.h"

Merchant::Merchant() : Card("Merchant"){}

void Merchant::applyEncounter(std::shared_ptr<Player> player) {
    int coins = player->getCoins();
    std::string name = player->getName();
    std::string input;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, name, coins);
    getline(std::cin, input);
    int inputOfPlayer = stoi (input);
    while (1) { // check input + do stuff
        if (inputOfPlayer == FIRST_INPUT) { // not buying
            break;
        }
        if (inputOfPlayer == SECOND_INPUT) { // buy HP
            bool result = player->pay(PAY_HP);
            if (!result) {
                printMerchantInsufficientCoins(std::cout);
            }
            else {
                player->heal(GAINED_HP);
            }
            break;
        }
        if (inputOfPlayer == THIRD_INPUT) { // buy force
            bool result = player->pay(PAY_FORCE);
            if (!result) {
                printMerchantInsufficientCoins(std::cout);
            }
            else {
                player->forceUp();
            }
            break;
        }
        else {
            printInvalidInput();
            getline(std::cin, input);
            inputOfPlayer = stoi (input);
        }
    }
    int cost = coins - player->getCoins();
    printMerchantSummary(std::cout, name, inputOfPlayer, cost);
}