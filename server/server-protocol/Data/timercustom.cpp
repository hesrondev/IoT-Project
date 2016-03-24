#include "timercustom.h"

TimerCustom::TimerCustom(QTcpSocket *soc)
{
    socket = soc;

    connect(this, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
}

void TimerCustom::timeoutSlot()
{
    emit timeoutSignal(socket);
}
