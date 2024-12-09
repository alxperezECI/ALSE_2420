#include "ejemplopp.h"
#include <iostream>
#include "./ui_ejemplopp.h"
#include <dia_div.h>
#include <eigen3/Eigen/Dense>

ejemploPp::ejemploPp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ejemploPp)
{
    ui->setupUi(this);
    _tipo_div = 0;
    _escalar = 0.0;
}

ejemploPp::~ejemploPp()
{
    delete ui;
}

void ejemploPp::leerGUI()
{

}

void ejemploPp::escribirGUI()
{

}


void ejemploPp::on_cmd_Operar_clicked()
{
    Eigen::MatrixXd A(2,2),B(2,2), R(2,2);
    A(0,0) = ui->txt_A11->text().toDouble();
    A(0,1) = ui->txt_A12->text().toDouble();
    A(1,0) = ui->txt_A21->text().toDouble();
    A(1,1) = ui->txt_A22->text().toDouble();

    B(0,0) = ui->txt_B11->text().toDouble();
    B(0,1) = ui->txt_B12->text().toDouble();
    B(1,0) = ui->txt_B21->text().toDouble();
    B(1,1) = ui->txt_B22->text().toDouble();

    switch(ui->cbo_Operacion->currentIndex()){
    case 0:
        R = A + B;
        break;
    case 1:
        R = A - B;
        break;
    case 2:
        R = A * B;
        break;
    case 3:
        dia_div wsec(this);
        QObject::connect(&wsec,&dia_div::emitir_datos,this,&ejemploPp::recibir_datos);
        wsec.show();
        wsec.exec();
        std::cout << "tipo: " << _tipo_div << "y esc: " << _escalar << std::endl;
        switch(_tipo_div){
        case 0:
            R = A * B.inverse();
            break;
        case 1:
            R = B * A.inverse();
            break;
        case 2:
            R = A / _escalar;
            break;
        case 3:
            R = B / _escalar;
        }
    }

    ui->txt_R11->setText(QString::number(R(0,0)));
    ui->txt_R12->setText(QString::number(R(0,1)));
    ui->txt_R21->setText(QString::number(R(1,0)));
    ui->txt_R22->setText(QString::number(R(1,1)));
}

void ejemploPp::recibir_datos(int tipo, double esc)
{
   _tipo_div = tipo;
   _escalar = esc;
}

