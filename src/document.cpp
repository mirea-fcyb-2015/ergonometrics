#include "document.h"

Document::Document(QObject *parent) : QObject(parent)
{

}

void Document::loadDocument(string fileName)
{
    this->fileName = fileName;

    Parser parser(fileName);
    controls = parser.Exec();
}

void Document::getControlDetails()
{
    emit ControlDetails(controls);
}
