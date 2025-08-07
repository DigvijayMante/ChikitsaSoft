#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();

    QPixmap pixmap("D:/Qt_Projects/ChikitsaSoft/images/MedicalBackground2.jpg");
    // ui->label->setScaledContents(true);  // optional
    ui->label->setPixmap(pixmap.scaled(ui->label->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));


}

MainWindow::~MainWindow()
{
    delete ui;
}
