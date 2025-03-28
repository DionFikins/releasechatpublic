#ifndef CONTROLMENU_HPP
#define CONTROLMENU_HPP

#include <QDialog>

namespace Ui {
  class ControlMenu;
}

class ControlMenu : public QDialog
{
  Q_OBJECT

public:
  explicit ControlMenu(QWidget *parent = nullptr);
  ~ControlMenu();

  void setLoginForm();
  void setRegistrationForm();

private:
  Ui::ControlMenu *ui;
};

#endif // CONTROLMENU_HPP
