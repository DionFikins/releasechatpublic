#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow) {
  ui->setupUi(this);
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

}
