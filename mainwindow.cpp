#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_newConnection_triggered() {

}

void MainWindow::on_exitProgram_triggered() {

}

void MainWindow::on_openPrivateChat_triggered() {

}
