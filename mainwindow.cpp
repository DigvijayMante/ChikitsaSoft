#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    SetUpUi();
    ConnectMethods();
}

void MainWindow::SetUpUi()
{
    ui->setupUi(this);
    this->showMaximized();

    QString imagePath = getProjectImagePath("images/MedicalBackground2.jpg");

    QPixmap pixmap(imagePath);
    ui->label->setPixmap(pixmap.scaled(ui->label->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
}

QString  MainWindow::getProjectImagePath(const QString &relativePath)
{
    QDir dir(QCoreApplication::applicationDirPath());

    // Go up until we find "ChikitsaSoft" or reach drive root
    while ((dir.dirName().compare("ChikitsaSoft", Qt::CaseInsensitive) != 0) && dir.cdUp())
    {
        if (dir.isRoot())
            break;
    }

    return dir.filePath(relativePath);
}

void MainWindow::ConnectMethods()
{
    QObject::connect(ui->actionOpenInventory, &QAction::triggered, this, &MainWindow::onInventoryManager_Clicked);
}
void MainWindow::onInventoryManager_Clicked()
{


}

MainWindow::~MainWindow()
{
    delete ui;
}
