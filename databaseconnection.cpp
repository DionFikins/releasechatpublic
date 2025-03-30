#include "databaseconnection.hpp"

bool DataBaseConnection::createConnection() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
  //db.setDatabaseName("Ваша база данных");
  //db.setUserName("Ваш пользователь от базы данных");
  //db.setPassword("Ваш пароль от базы данных");

  db.setDatabaseName("ai");
  db.setUserName("diofik");
  db.setPassword("garbe527_pech");

  if(!db.open()) {
    qDebug() << "Connection in database failed";
    return false;
  }
  else {
    qDebug() << "Connection in database complited!";
    return true;
  }
}

void DataBaseConnection::exitConnection() {
  QSqlDatabase db;
  db.close();
  qDebug() << "Connection close";
}

int DataBaseConnection::loginDB(QString login, QString pass) {
  QSqlQuery query;
  query.prepare("select id_user from users where login_user = :login and pass_user = :pass");
  query.bindValue(":login", login);
  query.bindValue(":pass", pass);
  if(query.lastError().isValid())
    qDebug() << query.lastError();
  query.exec();
  if(query.next()) return query.value(0).toInt();
  return -1;
}

void DataBaseConnection::registrationDB(QString login, QString pass, QString name) {
  QSqlQuery query;
  query.prepare("select count(*) from users where login_user = :login");
  query.bindValue(":login", login);
  query.exec();
  qDebug() << query.value(0).toInt();
  if(query.next()) {
      if(query.value(0).toInt() != 0) {
          qDebug() << "User is database";
        }
      else {
          query.clear();
          query.prepare("insert into users(login_user, pass_user, name_user) values(:login, :pass, :name)");
          query.bindValue(":login", login);
          query.bindValue(":pass", pass);
          query.bindValue(":name", name);
          if(query.lastError().isValid())
            qDebug() << query.lastError();
          query.exec();
        }
    }
}
