#ifndef REGISTRATIONFORM_HPP
#define REGISTRATIONFORM_HPP

#include <QWidget>

namespace Ui {
  class RegistrationForm;
}

class RegistrationForm : public QWidget
{
  Q_OBJECT

public:
  explicit RegistrationForm(QWidget *parent = nullptr);
  ~RegistrationForm();

private slots:
  void on_loginFormBtn_clicked();

  void on_buttonBox_accepted();

  void on_buttonBox_rejected();

private:
  Ui::RegistrationForm *ui;
};

#endif // REGISTRATIONFORM_HPP
