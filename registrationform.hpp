#ifndef REGISTRATIONFORM_HPP
#define REGISTRATIONFORM_HPP

#include <QWidget>
#include "connectiontoserver.hpp"
#include "databaseconnection.hpp"

namespace Ui {
  class RegistrationForm;
}

class RegistrationForm : public QWidget
{
  Q_OBJECT

public:
  explicit RegistrationForm(QWidget *parent = nullptr);
  ~RegistrationForm();

  ConnectionToServer *srv = new ConnectionToServer;
  DataBaseConnection *db = new DataBaseConnection;

signals:
  void loginRequested();

private slots:
  void on_loginFormBtn_clicked();
  void on_buttonBox_accepted();
  void on_buttonBox_rejected();

  void registrationUser();

private:
  Ui::RegistrationForm *ui;
};

#endif // REGISTRATIONFORM_HPP
