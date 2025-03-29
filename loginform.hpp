#ifndef LOGINFORM_HPP
#define LOGINFORM_HPP

#include <QWidget>

namespace Ui {
  class LoginForm;
}

class LoginForm : public QWidget
{
  Q_OBJECT

public:
  explicit LoginForm(QWidget *parent = nullptr);
  ~LoginForm();

private:
  Ui::LoginForm *ui;
};

#endif // LOGINFORM_HPP
