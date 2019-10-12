#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include <QMap>
#include "win.h"


/* --------- MODEL ------- */
class gameModel : public QObject {

    Q_OBJECT

private:
    int dice, currentScore, currentPlayer;
    QMap<int, int> players;

public:

    gameModel();
    void newGame();
    int getCurrentPlayer();


public slots:
    void newDice();
    void hold();
    void nextPlayer();

    signals:
    void updateDice(int dice);
    void updateTurnTotal(int turnTotal);
    void updateScore(int score);
    void newTurn(int player);
    void winner();

};

#endif // GAMEMODEL_H
