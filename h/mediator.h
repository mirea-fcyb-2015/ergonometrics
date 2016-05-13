#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>
#include <fstream>
#include <QObject>
#include "control.h"

using namespace std;

class Mediator : public QObject
{
    Q_OBJECT

signals:
    void loadDocumentSignal(string fileName);
    void CalculateCriterionsSignal(uint crt);
    void getControlDetailsSignal();
    void ControlDetailsSignal(vector<Control>);

public slots:
    void loadDocumentSlot(string fileName);
    void CalculateCriterionsSlot(uint crt);
    void getControlDetailsSlot();
    void ControlDetailsSlot(vector<Control>);
};

#endif // MEDIATOR_H
