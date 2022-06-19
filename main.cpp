
#include <functional>
#include <iostream>
#include "Mtmchkin.h"
#include "Exception.h"


int main(){
    try{
        Mtmchkin mtmchkin("deck.txt");
        while (!mtmchkin.isGameOver() && mtmchkin.getNumberOfRounds() < 100){
            mtmchkin.playRound();
            mtmchkin.printLeaderBoard();
        }
    }
    catch (Exception& exception){
        std::cout << exception.what();
    }
    catch (std::bad_alloc& alloc){
        std::cout << alloc.what();
    }
    catch (...){
        std::cerr << "fail of something" << std::endl;
    }
    return 0;
}