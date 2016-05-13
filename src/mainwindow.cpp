#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName();
    emit loadDocumentSignal(file.toStdString());
}

void MainWindow::on_pushButton_2_clicked()
{
    QList<QObject *> check = ui->groupBox->children();
    int criterions = 0;

    for(int i = 0; i < check.size(); i++)
    {
        if(((QCheckBox *)check[i])->isChecked())
            criterions += (1 << i);
    }

    emit CalculateCriterions(criterions);
}
