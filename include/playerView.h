#ifndef playerVIEW_H
#define PLAYERVIEW_H

#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QPixmap>
#include <QProgressBar>
#include "win.h"


class playerView {
private:
    int id;
    QLabel *dice, *pig, *temp, *total;
    QProgressBar* progress;
    QPixmap pix, pixWinner;
    friend class gameView;

public:
    playerView(int id, QString playerName, QLabel* playerLabel, QLabel *dice, QLabel *pig, QLabel *temp, QLabel *total, QProgressBar* progress);

    void reset();

    void init_bar();

    void myTurn();

    void nextTurn();

    void winner();


};


#endif // PLAYERVIEW_H
