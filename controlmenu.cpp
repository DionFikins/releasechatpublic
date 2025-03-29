#include "controlmenu.hpp"
#include "ui_controlmenu.h"

ControlMenu::ControlMenu(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ControlMenu)
{
  ui->setupUi(this);
}

ControlMenu::~ControlMenu()
{
  delete ui;
}
