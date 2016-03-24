#ifndef TIMERCUSTOM_H
#define TIMERCUSTOM_H

#include <QTimer>
#include <QtNetwork>

class TimerCustom : public QTimer
{
    Q_OBJECT

public:
    TimerCustom(QTcpSocket *soc);

public slots:
    void timeoutSlot();

signals:
    void timeoutSignal(QTcpSocket *socket);

private:
    QTcpSocket *socket;
};

#endif // TIMERCUSTOM_H
