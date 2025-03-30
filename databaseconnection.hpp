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

};
#endif // DATABASECONNECTION_HPP
