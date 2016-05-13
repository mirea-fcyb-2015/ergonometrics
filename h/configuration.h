#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include <vector>
#include "control.h"
#include "criterion.h"
#include "creator.h"

using namespace std;

class Configuration : public QObject
{
    Q_OBJECT
public:
    explicit Configuration(QObject *parent = 0);

    bool SaveCalculationResult();

private:
    vector<Criterion *> criterions;
    bool ControlsDetailSet = false;

signals:
    void getControlsDetail();

public slots:
    void CalculateCriterionsSlot(uint criterion);
    void ControlDetails(vector<Control>);
};

#endif // CONFIGURATION_H
