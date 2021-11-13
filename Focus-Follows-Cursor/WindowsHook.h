#ifndef WINDOWSHOOK_H
#define WINDOWSHOOK_H

#include <QObject>
#include <qt_windows.h>

class WindowsHook : public QObject
{
    Q_OBJECT
public:
    explicit WindowsHook(QObject *parent = nullptr);

//    void saveMousePos(long x, long y){
//        mousePos.setX(x);
//        mousePos.setY(y);
//    }
signals:

private:
    QPoint mousePos;
};


#endif // WINDOWSHOOK_H
