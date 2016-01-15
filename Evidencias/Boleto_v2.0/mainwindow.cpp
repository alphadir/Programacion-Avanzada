#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

QVector <QString> NewE;
QVector <int> BolV;
QVector <int> compr;
int lock;
QVector <int> newE;

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
    compr.push_back(0);
    newE.push_back(0);
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
    ui->listWidget_3->clear();
    ui->listWidget_2->clear();
    ui->listWidget->clear();
    if (lock==1){
        for(int j=0; j<BolV.size();j++){
            BolV.remove(j);
            compr.remove(j);
            newE.remove(j);
        }
    lock=0;
    }
    else{
        for(int j=0; j<BolV.size();j++){
            BolV.remove(j);
            compr.remove(j);
            newE.remove(j);

        }
    }
    ui->cancel->setEnabled(false);

}

void MainWindow::on_add_clicked()
{
    lock=1;
    ui->ok->setEnabled(true);
    ui->cancel->setEnabled(true);
    ui->edit->setEnabled(true);
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    //newE.push_back(ui->listWidget->currentRow());
//  QMessageBox::information(this, "vendido", QString::number(numnum));
    BolV[ui->listWidget->currentRow()]++;
    ui->listWidget_2->item(ui->listWidget->currentRow())->setText(QString::number(BolV[ui->listWidget->currentRow()]));
    compr[ui->listWidget->currentRow()]++;

}

void MainWindow::on_resumen_clicked()
{

}

void MainWindow::on_total_clicked()
{
    int tamanio=BolV.size();
    int total=0;
    for (int i=0 ; i < tamanio ; i++){
        total = total + BolV [i];
    }
    QMessageBox::information(this, "total", "Boletos Vendidos: " +QString::number(total));
}

void MainWindow::on_comprar_clicked()
{
    int comprar = BolV.size();
    ui->listWidget_3->clear();
    for (int i=0; i<comprar; i++){
        ui->listWidget_3->addItem(ui->listWidget->item(i)->text()+":\t"+QString::number(compr[i])+" boletos comprados");
    }
    ui->cancel->setEnabled(true);
}
