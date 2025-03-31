#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QTextEdit>
#include <QKeyEvent>
#include "controlmenu.hpp"
#include "connectiontoserver.hpp"
#include "databaseconnection.hpp"
#include "loginform.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  static MainWindow *createClient();

  ConnectionToServer *srv = new ConnectionToServer;
  DataBaseConnection *db = new DataBaseConnection;
  LoginForm lg;

private slots:
  void on_newConnection_triggered();
  void on_exitProgram_triggered();
  void on_openPrivateChat_triggered();
  void on_updateChats_triggered();

  void TableViewLoadPublic();
  void TableViewLoadPrivate(QString name, int idUser);

  void on_publicEdit_returnPressed();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
