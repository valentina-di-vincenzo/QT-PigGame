#include "include/gameController.h"
#include "include/gameView.h"

gameController::gameController(QString playerName1, QString playerName2) {
            view = new gameView(playerName1, playerName2);
            model = new gameModel();
}


void gameController::init() {

    // NEW GAME
    QObject::connect(view, &gameView::newGame, model, &gameModel::newGame);

    // NEW TURN
    QObject::connect(model, SIGNAL(newTurn(int)), view, SLOT(newTurn(int)));

    // ROLL
    QObject::connect(view, &gameView::roll, model, &gameModel::newDice);

    // UPDATE DICE
    QObject::connect(model, SIGNAL(updateDice(int)), view, SLOT(updateDice(int)));

    // HOLD
    QObject::connect(view, &gameView::hold, model, &gameModel::hold);

    // UPDATE TURN TOTAL
    QObject::connect(model, SIGNAL(updateTurnTotal(int)), view, SLOT(updateTurnTotal(int)));

    // UPDATE SCORE
    QObject::connect(model, SIGNAL(updateScore(int)), view, SLOT(updateScore(int)));

    // WINNER
    QObject::connect(model, &gameModel::winner, view, &gameView::winner);

    view->exec();
}


