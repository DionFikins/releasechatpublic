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
  ui->loginEdit->text().clear();
  ui->passEdit->text().clear();
  ui->nameEdit->text().clear();
}

void RegistrationForm::registrationUser() {
  srv->ConnServer();
  qDebug() << ui->loginEdit->text();
  qDebug() << ui->passEdit->text();
  qDebug() << ui->nameEdit->text();
  srv->EnterMessage("insert into users (login_user, pass_user, name_user) values ('"
                    + ui->loginEdit->text().toStdString()
                    + "', '" + ui->passEdit->text().toStdString()
                    + "', '" + ui->nameEdit->text().toStdString() + "')");
  std::string value = srv->ServerUpdate();
  qDebug() << value.c_str();
}
