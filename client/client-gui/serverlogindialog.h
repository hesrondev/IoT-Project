#ifndef SERVERLOGINDIALOG_H
#define SERVERLOGINDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>

class ServerLoginDialog : public QDialog
{
    Q_OBJECT

    friend class MainWindow;

public:
    ServerLoginDialog();

public slots:
    void validBtnClicked();

signals:
    void serverConnectionSignal(const QString &ip, const QString &port, const QString &clientName, const QString &mdp);

private:

    QPushButton *cancelBtn;
    QPushButton *validBtn;
    QLineEdit *addressLE;
    QLineEdit *portLE;
    QLineEdit *nameLE;
    QLineEdit *passwordLE;
    QCheckBox *rememberCBox;

};

#endif // SERVERLOGINDIALOG_H
