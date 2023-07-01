#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string &fileName) :
                m_numberOfRounds(GAME_START_ROUNDS), m_cardQueue(),m_playerVector(),m_winners(),m_losers(){
    createCardQueue(fileName, m_cardQueue);
    m_playerVector = createPlayers();
}

void Mtmchkin::playRound() {
    m_numberOfRounds++;
    printRoundStartMessage(m_numberOfRounds);
    for (std::shared_ptr<Player> it : m_playerVector) {
        if (!(it->isPlaying())) { // if he won or lost before
            // skip this player
            continue;
        }
        std::shared_ptr<Card> currentCard = m_cardQueue.front(); // draw card
        printTurnStartMessage(it->getName());
        currentCard->applyEncounter(it);
        m_cardQueue.pop(); // pop the head and push back to end of queue
        m_cardQueue.push(currentCard);
        if (!(it->isPlaying())) { // if he lost / won while encounter
            if (it->isKnockedOut()) {
                m_losers.insert(m_losers.begin(), it);
            }
            else { // this player won
                m_winners.push_back(it);
            }
        }
    }
    if (isGameOver()){
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int rankingToPrint = 1; // start from winner
    for (std::shared_ptr<Player> it : m_winners){
        printPlayerLeaderBoard(rankingToPrint, *it);
        rankingToPrint++;
    }
    for (std::shared_ptr<Player> it : m_playerVector){
        if (it->isPlaying()) {
            printPlayerLeaderBoard(rankingToPrint, *it);
            rankingToPrint++;
        }
    }
    for (std::shared_ptr<Player> it : m_losers){
        printPlayerLeaderBoard(rankingToPrint, *it);
        rankingToPrint++;
    }
}

bool Mtmchkin::isGameOver() const {
    bool answer = false;
    int counter = 0;
    for (std::shared_ptr<Player> it : m_playerVector) {
        if (!(it->isPlaying())) { // if he won or lost before
            counter++;
        }
    }
    if (counter == m_playerVector.size()){
        answer = true;
    }
    return answer;
}

 int Mtmchkin::getNumberOfRounds() const {
    return m_numberOfRounds;
}