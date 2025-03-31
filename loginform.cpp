#include "loginform.hpp"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::LoginForm) {
  ui->setupUi(this);
}

LoginForm::~LoginForm() { delete ui; }

void LoginForm::on_registrationFormBtn_clicked() { emit registrationRequested(); }

void LoginForm::on_buttonBox_accepted() { Logining(); }

void LoginForm::on_buttonBox_rejected() {
  ui->loginEdit->clear();
  ui->passwordEdit->clear();
}

void LoginForm::Logining() {
  _idLoginUser = db->loginDB(ui->loginEdit->text(), ui->passwordEdit->text());
  db->setIdLogin(_idLoginUser);
  qDebug() << "Logining";
  qDebug() << db->getIdLogin();
  this->on_buttonBox_rejected();
}
