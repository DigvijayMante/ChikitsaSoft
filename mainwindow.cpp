#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();

    QString AbsolutePath;
    QString CurrentDir = QDir::currentPath();

    QFileInfo info(CurrentDir);
    AbsolutePath = info.absolutePath();
    AbsolutePath += "/ChikitsaSoft/images/MedicalBackground2.jpg";

    QPixmap pixmap(AbsolutePath);
    ui->label->setPixmap(pixmap.scaled(ui->label->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

}

MainWindow::~MainWindow()
{
    delete ui;
}
