#ifndef WELCOMEDIALOG_H
#define WELCOMEDIALOG_H


#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class welcomeDialog;
}

class welcomeDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcomeDialog(QWidget *parent = nullptr);
    ~welcomeDialog();

private slots:
    void on_play_clicked();

private:
    Ui::welcomeDialog *ui;
    void init_player(QLineEdit* player, QString name);
};

#endif // WELCOMEDIALOG_H
