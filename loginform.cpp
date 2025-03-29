#include "loginform.hpp"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::LoginForm)
{
  ui->setupUi(this);
}

LoginForm::~LoginForm()
{
  delete ui;
}

void LoginForm::on_registrationFormBtn_clicked()
{

}


void LoginForm::on_buttonBox_accepted()
{

}

