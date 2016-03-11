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
public:
    ServerLoginDialog();

private:

    QPushButton *cancelBtn;
    QPushButton *validBtn;
    QLineEdit *addressLE;
    QLineEdit *portLE;
    QLineEdit *passwordLE;
    QCheckBox *rememberCBox;

};

#endif // SERVERLOGINDIALOG_H
