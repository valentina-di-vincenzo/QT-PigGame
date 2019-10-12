#include "include/welcomeDialog.h"
#include "ui_welcomedialog.h"
#include "include/gameController.h"

welcomeDialog::welcomeDialog(QWidget *parent) : QMainWindow(parent), ui(new Ui::welcomeDialog) {
    ui->setupUi(this);
    setFixedSize(358, 286);

    init_player(ui->playerName1, "player 1");
    init_player(ui->playerName2, "player 2");

    QPixmap pix(":/img/img/pig_icon");
    ui->pig_icon->setPixmap(pix);

    QFile file(":/style/welcomeStyle.qss");
    if(file.open(QFile::ReadOnly)) {
       QString stylesheet = QLatin1String(file.readAll());
       qApp->setStyleSheet(stylesheet);
    }

}

welcomeDialog::~welcomeDialog() {

    delete ui;

}

void welcomeDialog::on_play_clicked() {

    this->close();
    gameController gc(ui->playerName1->text(), ui->playerName2->text());
    gc.init();

}

void welcomeDialog::init_player(QLineEdit* player, QString name) {

    player->setAttribute(Qt::WA_MacShowFocusRect, 0);
    player->setPlaceholderText(name);

}

