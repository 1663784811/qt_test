#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include <QFile>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //在相应Widget的构造函数里
    //设置无边框窗口
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    //设置主窗口透明
    this->setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(10);
    shadow->setColor(Qt::black);
    shadow->setOffset(0);
    ui->widget->setGraphicsEffect(shadow);


    QHeaderView headerView(Qt::Horizontal);

    QStringList table_h_headers;
    for(int i = 0; i< 10; i++){
        table_h_headers.append("sssssssssss");
    }

    // ui->tableView->setHorizontalHeader(table_h_headers);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *evt)
{
    isdown = true;
    mOffset = evt->globalPosition().toPoint() - this->pos();
    qDebug() << "mouse down";
}

void MainWindow::mouseMoveEvent(QMouseEvent *evt)
{
    if(isdown){
        this->move(evt->globalPosition().toPoint()-mOffset);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *evt)
{
    isdown = false;
}


void MainWindow::on_closeBtn_clicked()
{
    close();
}

void MainWindow::on_maxWinBtn_clicked()
{
    if(isMaximized()){
        showNormal();
    }else{
        showMaximized();
    }
}


void MainWindow::on_toolButton_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, "sss", ".");
    QStringList files = getFiles(path);
    for (int i = 0; i < files.count(); ++i) {
        QString fileStr = files.at(i);
        // 读取文件
        QFile qfile(fileStr);
        if(qfile.open(QIODevice::ReadOnly)){
            QByteArray qbyteArr = qfile.readLine();


            std::string a = qbyteArr.toStdString();

            qfile.close();
        }
    }
}

QStringList MainWindow::getFiles(const QString &path)
{
    QStringList rest;
    QDir dir(path);
    QFileInfoList infolist = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for (int i = 0; i < infolist.count(); ++i) {
        QFileInfo info = infolist.at(i);
        if(info.isDir()){
            QString suDir = info.absoluteFilePath();
            QStringList files = getFiles(suDir);
            rest.append(files);
        }else{
            rest.append(info.absoluteFilePath());
        }
    }
    return rest;
}

