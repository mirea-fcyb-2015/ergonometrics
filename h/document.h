#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>
#include <string>
#include "parser.h"

using namespace std;

class Document : public QObject
{
    Q_OBJECT
public:
    explicit Document(QObject *parent = 0);

private:
    string fileName;
    vector<Control> controls;

signals:

public slots:
    void loadDocument(string fileName);
};

#endif // DOCUMENT_H
