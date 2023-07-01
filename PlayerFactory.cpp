#include "PlayerFactory.h"

int checkTeamSize(){
    int teamNumber;
    while (1) { // get the team size of the players
        printEnterTeamSizeMessage();
        std::string teamSize;
        std::getline(std::cin, teamSize);
        try{ // check that the input is an integer
            teamNumber = stoi (teamSize);
        }
        catch(const std::exception& e){
            printInvalidTeamSize();
        }
        if (teamNumber < MIN_TEAM_SIZE || teamNumber > MAX_TEAM_SIZE) {
            printInvalidTeamSize();
            continue;
        }
        break;
    }
    return teamNumber;
}

std::vector<std::string> createVectorInput(){
    std::vector<std::string> inputStrings;
    std::string str1Str2, temp;
    getline(std::cin, str1Str2);
    long unsigned int i = 0;
    while (i < str1Str2.size()){
        while (str1Str2[i] == SPACE && i < str1Str2.size()){ // not in a word
            i++;
        }
        while (str1Str2[i] != SPACE && i < str1Str2.size()){ // in a word
            temp += str1Str2[i];
            i++;
        }
        if (str1Str2[i] == SPACE && str1Str2[i - 1] != SPACE){ // not in a word
            inputStrings.push_back(temp);
            temp = "";
        }
        if (str1Str2[i] != SPACE && i + 1 > str1Str2.size()){
            inputStrings.push_back(temp);
        }
    }
    return inputStrings;
}

bool checkName (std::string name){
    bool check = true;
    if (name.size() > MAX_LEN){
        check = false;
    }
    else {
        for (char c : name){
            if (!isalpha(c)){
                check = false;
                break;
            }
        }
    }
    return check;
}

std::shared_ptr<Player> createPlayer() {
    std::vector<std::string> inputStrings;
    printInsertPlayerMessage();
    while (1) { // check input
        inputStrings = createVectorInput(); // create words for input
        if (inputStrings.size() != INPUT_SIZE) {
            printInvalidInput();
        }
        else {
            std::string name = inputStrings.front(); // first value
            std::string job = inputStrings[1]; // second value
            bool nameResult = checkName(name);
            if (!nameResult) {
                printInvalidName();
            }
            else { // name is correct
                if (job == "Ninja") {
                    return std::make_shared<Ninja>(name);
                }
                if (job == "Healer") {
                    return std::make_shared<Healer>(name);
                }
                if (job == "Warrior") {
                    return std::make_shared<Warrior>(name);
                }
                else {
                    printInvalidClass();
                }
            }
        }
    }
}

std::vector<std::shared_ptr<Player>> createPlayers() {
    int teamSize = checkTeamSize(); // get team size
    std::vector<std::shared_ptr<Player>> playerVector;
    for (int i = 0; i < teamSize; i++){
        std::shared_ptr<Player> temp = createPlayer();
        playerVector.push_back(temp); // push players into the vector
    }
    return playerVector;
}