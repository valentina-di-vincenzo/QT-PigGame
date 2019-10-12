#include "include/gameModel.h"


gameModel::gameModel() {

    players.insert(1, 0);
    players.insert(2, 0);
    newGame();

}


void gameModel::newGame() {

    players[1] = 0;
    players[2] = 0;
    currentScore = 0;
    dice = 0;
    currentPlayer = rand() % 2 + 1;
    emit newTurn(getCurrentPlayer());
}


int gameModel::getCurrentPlayer() {

    return currentPlayer;

}


void gameModel::newDice() {

    dice = (rand() % 6) + 1;
    emit updateDice(dice);
    if(dice != 1) {
        currentScore += dice;
        emit updateTurnTotal(currentScore);
    }
    else {
        emit updateTurnTotal(0);
        nextPlayer();
    }

}


void gameModel::hold() {

    players[currentPlayer] += currentScore;
    emit updateTurnTotal(0);

    emit updateScore(players[currentPlayer]);
    if(players[currentPlayer] >= WIN) {
        emit winner();

    } else {
    nextPlayer();
    }

}

void gameModel::nextPlayer() {

    currentScore = 0;
    if(currentPlayer == 1) {
        currentPlayer = 2;
       }
   else {
        currentPlayer = 1;
    }
    emit newTurn(currentPlayer);

}










