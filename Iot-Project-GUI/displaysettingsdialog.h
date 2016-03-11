#ifndef DISPLAYSETTINGSDIALOG_H
#define DISPLAYSETTINGSDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

class DisplaySettingsDialog : public QDialog
{
public:
    DisplaySettingsDialog();

    void initWidgets();

    ~DisplaySettingsDialog();

private:

    QSpinBox *processFqLE;
    QSpinBox *cpuFqLE;
    QSpinBox *memoryFqLE;
    QSpinBox *diskFqLE;
    QSpinBox *ethFqLE;

    QPushButton *validButton;

};

#endif // DISPLAYSETTINGSDIALOG_H
