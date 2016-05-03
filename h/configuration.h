#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include "control.h"
#include "criterion.h"

class Configuration : public QObject
{
    Q_OBJECT
public:
    explicit Configuration(QObject *parent = 0);

    bool SaveCalculationResult();

private:
    vector<Criterion *> criterions;

signals:

public slots:
};

#endif // CONFIGURATION_H
