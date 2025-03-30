#ifndef LOGINFORM_HPP
#define LOGINFORM_HPP

#include <QWidget>
#include <QDebug>
#include "connectiontoserver.hpp"
#include "databaseconnection.hpp"

namespace Ui { class LoginForm; }

class LoginForm : public QWidget
{
  Q_OBJECT

public:
  explicit LoginForm(QWidget *parent = nullptr);
  ~LoginForm();

  ConnectionToServer *srv = new ConnectionToServer;
  DataBaseConnection *db = new DataBaseConnection;

  int _idLoginUser;

  void Logining();

signals:
  void registrationRequested();

private slots:
  void on_registrationFormBtn_clicked();
  void on_buttonBox_accepted();
  void on_buttonBox_rejected();

private:
  Ui::LoginForm *ui;
};

#endif // LOGINFORM_HPP
