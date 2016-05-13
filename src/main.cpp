#include "mainwindow.h"
#include "mediator.h"
#include "control.h"
#include "document.h"
#include "configuration.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    Mediator mediator;
    Document document;
    Configuration config;

    QObject::connect(&window, SIGNAL(loadDocumentSignal(string)), &mediator, SLOT(loadDocumentSlot(string)));
    QObject::connect(&mediator, SIGNAL(loadDocumentSignal(string)), &document, SLOT(loadDocument(string)));
    QObject::connect(&window, SIGNAL(CalculateCriterions(uint)), &mediator, SLOT(CalculateCriterionsSlot(uint)));
    QObject::connect(&mediator, SIGNAL(CalculateCriterionsSignal(uint)), &config, SLOT(CalculateCriterionsSlot(uint)));
    QObject::connect(&config, SIGNAL(getControlsDetail()), &mediator, SLOT(getControlDetailsSlot()));
    QObject::connect(&mediator, SIGNAL(getControlDetailsSignal()), &document, SLOT(getControlDetails()));
    QObject::connect(&document, SIGNAL(ControlDetails(vector<Control>)), &mediator, SLOT(ControlDetailsSlot(vector<Control>)));
    QObject::connect(&mediator, SIGNAL(ControlDetailsSignal(vector<Control>)), &config, SLOT(ControlDetails(vector<Control>)));

    window.show();

    return a.exec();
}
