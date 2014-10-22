#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "draw.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  Draw *d = new Draw(this);

  setCentralWidget(d);

}

MainWindow::~MainWindow()
{
  delete ui;
}
