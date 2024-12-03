#include "dia_div.h"
#include "ui_dia_div.h"

dia_div::dia_div(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dia_div)
{
    ui->setupUi(this);
}

dia_div::~dia_div()
{
    delete ui;
}

void dia_div::on_rb_AE_clicked(bool checked)
{
  if(ui->rb_AB->isChecked() || ui->rb_BA->isChecked()){
    ui->gb_Escalar->setEnabled(false);
  }else{
    ui->gb_Escalar->setEnabled(true);
  }
}


void dia_div::on_rb_BA_clicked()
{
    if(ui->rb_AB->isChecked() || ui->rb_BA->isChecked()){
      ui->gb_Escalar->setEnabled(false);
    }else{
      ui->gb_Escalar->setEnabled(true);
    }
}


void dia_div::on_rb_AE_clicked()
{
    if(ui->rb_AB->isChecked() || ui->rb_BA->isChecked()){
      ui->gb_Escalar->setEnabled(false);
    }else{
      ui->gb_Escalar->setEnabled(true);
    }
}

void dia_div::on_rb_BE_clicked()
{
    if(ui->rb_AB->isChecked() || ui->rb_BA->isChecked()){
      ui->gb_Escalar->setEnabled(false);
    }else{
      ui->gb_Escalar->setEnabled(true);
    }
}

