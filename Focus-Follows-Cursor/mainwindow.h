#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qt_windows.h>
#include <QTimer>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>

#define db qDebug() <<

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void checkMousePos();
    HWND getRealParent(HWND hWnd);
    void trayTriggered(QAction *action);

private:
    Ui::MainWindow *ui;
    QTimer * _posTimer;
    POINT _pCache;
    HWND _handle;
    QSystemTrayIcon * _trayIcon;
    QMenu *_trayMenu;
};
#endif // MAINWINDOW_H
