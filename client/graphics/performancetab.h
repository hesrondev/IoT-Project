#ifndef PERFORMANCETAB_H
#define PERFORMANCETAB_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>

#include "performancecustombutton.h"
#include "processortabdetails.h"
#include "memorytabdetails.h"
#include "disktabdetails.h"
#include "networktabdetails.h"

class PerformanceTab : public QWidget
{

    Q_OBJECT

public:
    PerformanceTab();

    void resetVLayout();

public slots:
    void setProcessorDetails();
    void setMemoryDetails();
    void setDiskDetails();
    void setNetworkDetails();

private:
    ProcessorTabDetails *processorDetails;
    MemoryTabDetails *memoryDetails;
    DiskTabDetails *diskDetails;
    NetworkTabDetails *networkDetails;

    // layout
    QVBoxLayout *vlayout;
};

#endif // PERFORMANCETAB_H
