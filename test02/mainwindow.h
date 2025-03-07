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
    void mousePressEvent(QMouseEvent *evt);
    void mouseMoveEvent(QMouseEvent *evt);
    void mouseReleaseEvent(QMouseEvent *evt);

private slots:
    void on_closeBtn_clicked();
    void on_maxWinBtn_clicked();
    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;
    bool isdown = false;
    QPoint mOffset;

    QStringList getFiles(const QString &path);
};
#endif // MAINWINDOW_H
