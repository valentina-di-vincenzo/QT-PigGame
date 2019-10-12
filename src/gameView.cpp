#include "include/gameView.h"
#include "ui_gameView.h"

gameView::gameView(QString playername1, QString playername2): ui(new Ui::gameView), playing(false) {

    ui->setupUi(this);
    setFixedSize(882, 661);
    ui->player1->setAlignment(Qt::AlignRight);

    playerView *player1 = new playerView(1, playername1, ui->player1, ui->dice1, ui->pig1, ui->turnTotal1, ui->score1, ui->progressBar1);
    playerView *player2 = new playerView(2, playername2, ui->player2, ui->dice2, ui->pig2, ui->turnTotal2, ui->score2, ui->progressBar2);

    players.insert(1, player1);
    players.insert(2, player2);
    currentPlayer = players[1];

    QFile file(":/style/style.qss");
    if(file.open(QFile::ReadOnly)) {
       QString stylesheet = QLatin1String(file.readAll());
       qApp->setStyleSheet(stylesheet);
    }

}

gameView::~gameView() {

    done(1);
    delete ui;

}

void gameView::updateDice(int newDice) {

   QPixmap pix(":/img/dices/" + QString::number(newDice));
   currentPlayer->dice->setPixmap(pix);

}

void gameView::updateScore(int score) {

    currentPlayer->total->setNum(score);
    currentPlayer->progress->setValue(score);

}

void gameView::updateTurnTotal(int temp) {

    currentPlayer->temp->setNum(temp);

}


void gameView::newTurn(int playerId) {

    currentPlayer->nextTurn();
    currentPlayer = players[playerId];
    currentPlayer->myTurn();

}

void gameView::winner() {

    currentPlayer->winner();
    playing = false;

}

void gameView::on_newGame_clicked() {

    players[1]->reset();
    players[2]->reset();
    playing = true;
    emit newGame();

}

void gameView::on_roll1_clicked() {

    if(currentPlayer->id == 1 && playing) emit roll();

}

void gameView::on_roll2_clicked() {

    if(currentPlayer->id == 2 && playing) emit roll();

}

void gameView::on_hold1_clicked() {

    if(currentPlayer->id == 1 && playing) emit hold();

}


void gameView::on_hold2_clicked() {

    if(currentPlayer->id == 2 && playing) emit hold();

}
