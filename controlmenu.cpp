#include "controlmenu.hpp"
#include "ui_controlmenu.h"

ControlMenu::ControlMenu(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ControlMenu)
{
  ui->setupUi(this);
  connect(ui->loginwidget, &LoginForm::registrationRequested, this, &ControlMenu::setRegistrationForm);
  connect(ui->registrationwidget, &RegistrationForm::loginRequested, this, &ControlMenu::setLoginForm);
}

ControlMenu::~ControlMenu() { delete ui; }

void ControlMenu::setLoginForm() { ui->stackedWidget->setCurrentIndex(0); }

void ControlMenu::setRegistrationForm() { ui->stackedWidget->setCurrentIndex(1); }
