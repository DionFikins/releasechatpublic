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

private:
  Ui::RegistrationForm *ui;
};

#endif // REGISTRATIONFORM_HPP
