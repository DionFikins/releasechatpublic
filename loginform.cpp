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

void LoginForm::on_buttonBox_rejected() { this->close(); }

void LoginForm::Logining() {
  srv->ConnServer();
  if(srv->connectionstatus != 0) qDebug() << "Error connection program";
  else {
    qDebug() << ui->loginEdit->text();
    qDebug() << ui->passwordEdit->text();
    srv->EnterMessage("select id_user from users where login_user = '"
                      + ui->loginEdit->text().toStdString()
                      + "' and pass_user = '" + ui->passwordEdit->text().toStdString() + "'");
    std::string value = srv->ServerUpdate();
    _idLogin = atoi(value.c_str());
  }
}
