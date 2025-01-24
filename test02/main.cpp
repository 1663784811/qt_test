#include "mainwindow.h"
#include <QSystemTrayIcon>
#include <QApplication>
#include <QMenu>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSystemTrayIcon trayIcon(QIcon(":/img/icon.png"), &a);
    // 创建右键菜单
    QMenu *menu = new QMenu();
    QAction *closeAction = menu->addAction("关闭程序");
    // 将菜单设置给托盘图标
    trayIcon.setContextMenu(menu);
    // 连接关闭程序的槽函数
    QObject::connect(closeAction, &QAction::triggered, &a, &QApplication::quit);
    // 显示托盘图标
    trayIcon.show();
    return a.exec();
}



