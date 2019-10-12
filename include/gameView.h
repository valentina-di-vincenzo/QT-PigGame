#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QPixmap>
#include <QProgressBar>
#include <QFile>

#include "playerView.h"
#include "win.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gameView; }
QT_END_NAMESPACE

/* --------- VIEW ------- */
class gameView : public QDialog
{
    Q_OBJECT

private:

    Ui::gameView *ui;
    playerView *currentPlayer;
    QMap<int, playerView*> players;
    bool playing;

public:
    gameView(QString playername1, QString playername2);
    ~gameView();

private slots:
    void on_newGame_clicked();
    void on_roll1_clicked();
    void on_roll2_clicked();
    void on_hold1_clicked();
    void on_hold2_clicked();

public slots:
    void newTurn(int player);
    void updateDice(int newDice);
    void updateScore(int score);
    void updateTurnTotal(int temp);
    void winner();

signals:
    void roll();
    void newGame();
    void hold();

};



#endif // GAMEVIEW_H
