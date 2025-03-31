#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow) {
  ui->setupUi(this);
  db->createConnection();
}

MainWindow::~MainWindow() { delete ui; }

MainWindow *MainWindow::createClient() {
  ControlMenu cm;
  cm.exec();
  return nullptr;
}

void MainWindow::on_newConnection_triggered() {
  createClient();
}

void MainWindow::on_exitProgram_triggered() { this->close(); }

void MainWindow::on_openPrivateChat_triggered() {

}

void MainWindow::on_updateChats_triggered() {
  qDebug() << db->getIdLogin();
  if(db->getIdLogin() != 0) {
      TableViewLoadPublic();
      TableViewLoadPrivate(ui->privateEdit->text(), db->getIdLogin());
    }
}

void MainWindow::TableViewLoadPublic() {
  QVector<QString> val;
  val.push_back("ID");
  val.push_back("Name");
  val.push_back("Message");

  QSqlQueryModel *query = new QSqlQueryModel(this);
  query->setQuery("select id_message, us.name_user, message_chatall from all_chat as ac inner join users as us on us.id_user = ac.id_user");
  if(query->lastError().isValid())
    qDebug() << query->lastError();

  for(int i = 0, j = 0; i < query->columnCount(); i++, j++)
    query->setHeaderData(i,Qt::Horizontal, val[j]);

  ui->publicView->setModel(query);
  ui->publicView->setColumnHidden(0,true);
  ui->publicView->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->publicView->setSelectionMode(QAbstractItemView::SingleSelection);
  ui->publicView->resizeColumnsToContents();
  ui->publicView->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->publicView->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::TableViewLoadPrivate(QString name, int idUser) {
  QVector<QString> val;
  val.push_back("ID");
  val.push_back("Name");
  val.push_back("Message");

  QString s = QString::number(idUser);

  QSqlQueryModel *query = new QSqlQueryModel(this);
  query->setQuery("select msg.id_message_chat, us.name_user, msg.message_chat from chat_users as cu \
                  inner join msg_usr_chat as msg on cu.id_chat = msg.id_chat \
                  inner join users as us on us.id_user = msg.id_user_upload \
                  where cu.id_useroutput = '" + s + "' \
                  and cu.id_userinput = (select id_user from users where name_user = '" + name + "')");
  if(query->lastError().isValid())
    qDebug() << query->lastError();

  for(int i = 0, j = 0; i < query->columnCount(); i++, j++)
    query->setHeaderData(i,Qt::Horizontal,val[j]);

  ui->privateView->setModel(query);
  ui->privateView->setColumnHidden(0,true);
  ui->privateView->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->privateView->setSelectionMode(QAbstractItemView::SingleSelection);
  ui->privateView->resizeColumnsToContents();
  ui->privateView->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->privateView->horizontalHeader()->setStretchLastSection(true);
}


void MainWindow::on_publicEdit_returnPressed()
{
    QKeyEvent *e;
    if(e->KeyPress == Qt::Key_Enter)
      db->insertDBprivate(ui->privateEdit->text(), db->getIdLogin(), ui->userEdit->text());
}

