#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>
#include <fstream>
#include <QObject>

using namespace std;

class Mediator : public QObject
{
    Q_OBJECT

signals:
    void loadDocumentSignal(string fileName);

public slots:
    void loadDocumentSlot(string fileName);
};

#endif // MEDIATOR_H
