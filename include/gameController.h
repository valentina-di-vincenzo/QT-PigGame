#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gameModel.h"
#include "gameView.h"

class gameController : public QObject {

    Q_OBJECT

private:
    gameView* view;
    gameModel* model;

public:
    gameController(QString username1, QString username2);
    void init();
};

#endif // GAMECONTROLLER_H
