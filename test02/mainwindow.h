#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




protected:
    // 重写鼠标按下事件
    // 重写鼠标移动事件
    void mousePressEvent(QMouseEvent *evt);
    void mouseMoveEvent(QMouseEvent *evt);
    void mouseReleaseEvent(QMouseEvent *evt);

private:
    Ui::MainWindow *ui;
    bool isdown = false;
    QPoint mOffset;

};
#endif // MAINWINDOW_H
