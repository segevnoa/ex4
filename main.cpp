#include "Mtmchkin.h"

int main (){
    try{
        Mtmchkin game("cards.txt");
        while(!game.isGameOver()){
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(const std::exception& error){
        std::cout << error.what() << std::endl;
    }
    return 0;
}