#include "include/playerView.h"


playerView::playerView(int id, QString playerName, QLabel* playerLabel, QLabel *dice, QLabel *pig, QLabel *temp, QLabel *total, QProgressBar* progress) : id(id), dice(dice), pig(pig), temp(temp), total(total), progress(progress) {

        init_bar();

        if(playerName == "") {
            playerName = "player " + QString::number(id);
        }
        playerLabel->setText(playerName);
        pix = QPixmap(":/img/img/pig" + QString::number(id));
        pixWinner = QPixmap(":/img/img/win");


}

void playerView::reset() {

    dice->clear();
    temp->clear();
    total->clear();
    progress->reset();

}

void playerView::init_bar() {

    progress->setMaximum(WIN);
    progress->setTextVisible(false);
    progress->reset();

}

void playerView::myTurn() {

    pig->setPixmap(pix);

}

void playerView::nextTurn() {

    pig->clear();

}

void playerView::winner() {

    dice->setPixmap(pixWinner);
    progress->setValue(progress->maximum());

}




