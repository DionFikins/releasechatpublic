#include "registrationform.hpp"
#include "ui_registrationform.h"

RegistrationForm::RegistrationForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::RegistrationForm) {
  ui->setupUi(this);
}

RegistrationForm::~RegistrationForm() { delete ui; }

void RegistrationForm::on_loginFormBtn_clicked() { emit loginRequested(); }
void RegistrationForm::on_buttonBox_accepted() { registrationUser(); }

void RegistrationForm::on_buttonBox_rejected() {
  ui->loginEdit->clear();
  ui->passEdit->clear();
  ui->nameEdit->clear();
}

void RegistrationForm::registrationUser() {
  db->registrationDB(ui->loginEdit->text(), ui->passEdit->text(), ui->nameEdit->text());
  qDebug() << "Registration complited";
  this->on_buttonBox_rejected();
}
