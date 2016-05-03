#include "mainwindow.h"
#include "mediator.h"
#include "control.h"
#include "document.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    Mediator mediator;
    Document document;

    QObject::connect(&window, SIGNAL(loadDocumentSignal(string)), &mediator, SLOT(loadDocumentSlot(string)));
    QObject::connect(&mediator, SIGNAL(loadDocumentSignal(string)), &document, SLOT(loadDocument(string)));

    window.show();

    return a.exec();
}
