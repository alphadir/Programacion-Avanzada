#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

QVector <QString> NewE;
QVector <int> BolV;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->edit->setEnabled(false);
    ui->cancel->setEnabled(false);
    ui->ok->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ok_clicked()
{
    QString Evento;
    Evento = ui->edit->text();
    NewE.push_back(Evento);
    BolV.push_back(0);
    ui->listWidget->addItem(Evento);
    ui->listWidget_2->addItem(QString::number(0));
    ui->edit->clear();
    ui->cancel->setEnabled(false);
    ui->ok->setEnabled(false);
    ui->edit->setEnabled(false);
}

void MainWindow::on_cancel_clicked()
{
    ui->edit->clear();
    ui->cancel->setEnabled(false);
    ui->ok->setEnabled(false);
    ui->edit->setEnabled(false);
}

void MainWindow::on_add_clicked()
{
    ui->ok->setEnabled(true);
    ui->cancel->setEnabled(true);
    ui->edit->setEnabled(true);
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    int newE = ui->listWidget->currentRow();
//  QMessageBox::information(this, "vendido", QString::number(numnum));
    BolV[newE]++;
    ui->listWidget_2->item(newE)->setText(QString::number(BolV[newE]));
}

void MainWindow::on_resumen_clicked()
{
    int tamanio=BolV.size();
    int total=0;
    for (int i=0 ; i < tamanio ; i++){
        total = total + BolV [i];
    }
    QMessageBox::information(this, "resumen", "Boletos Vendidos: " +QString::number(total));
}
