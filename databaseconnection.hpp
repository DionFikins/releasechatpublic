#ifndef DATABASECONNECTION_HPP
#define DATABASECONNECTION_HPP

#include <iostream>
#include <QDebug>
#include <QtSql/QSql>
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QSqlError>

using namespace std;

class DataBaseConnection {
public:
  bool createConnection();
  void exitConnection();
  int loginDB(QString login, QString pass);
  void registrationDB(QString login, QString pass, QString name);
  void insertDBpublic(QString text, int idLogin);
  int selectId(QString idTo);
  int countDB(QString idTo, int idLogin);
  void insertDBprivate(QString text, int idLogin, QString idTo);
  const int getIdLogin() const;
  const void setIdLogin(int value);
protected:
  int _idLogin;
};
#endif // DATABASECONNECTION_HPP
