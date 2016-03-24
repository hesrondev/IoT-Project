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
#include <QGroupBox>
#include <QCheckBox>

class DisplaySettingsDialog : public QDialog
{
    Q_OBJECT

public:
    DisplaySettingsDialog();

    void initWidgets();
    ~DisplaySettingsDialog();

public slots:
    void enableCompsGroup();
    void enableGlobalGroup();
    void on_validButton_clicked();

signals:
    void globalParam(int gp);
    void componentsParams(int pro, int cpu, int mem, int disk, int eth);

private:

    QSpinBox *processFqSB;
    QSpinBox *cpuFqSB;
    QSpinBox *memoryFqSB;
    QSpinBox *diskFqSB;
    QSpinBox *ethFqSB;
    QSpinBox *globalSB;

    QGroupBox *globalGroup;
    QGroupBox *byCompsGroup;

    QPushButton *validButton;

    QCheckBox *byCompsCB;
    QCheckBox *globCB;

};

#endif // DISPLAYSETTINGSDIALOG_H
