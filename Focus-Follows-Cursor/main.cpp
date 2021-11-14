#include "mainwindow.h"

#include <QApplication>



class HideFromTaskbar : public QWidget
{
public:
    HideFromTaskbar(QWidget *parent)
        : QWidget(parent, Qt::Dialog)
    {

    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // Make application a widget from a widget
    // Hides it from taskbar, and you don't need a tray entry
//    HideFromTaskbar widget(&w);
    return a.exec();
}
