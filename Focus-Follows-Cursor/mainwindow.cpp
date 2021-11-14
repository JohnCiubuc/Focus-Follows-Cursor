#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	_posTimer = new QTimer(this);
	connect(_posTimer, &QTimer::timeout, this, &MainWindow::checkMousePos);
	_posTimer->start(100);
    _trayIcon = new QSystemTrayIcon(this);
    _trayMenu = new QMenu(this);
_trayMenu->addAction("quit");
connect(_trayMenu, &QMenu::triggered, this, &MainWindow::trayTriggered);
_trayIcon->setContextMenu(_trayMenu);
_trayIcon->setIcon(QIcon("://resources/img_231546.png"));
_trayIcon->show();
}


MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::checkMousePos()
{
	POINT p;
	HWND handle;

	GetCursorPos(&p);
	if (_pCache.x != p.x ||
	        _pCache.y != p.y)
	{
		_pCache = p;

		handle = (WindowFromPoint(_pCache));
		if (_handle != handle)
		{
			_handle = handle;
			if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0) return;

			// Alt key pressing to activate windows
			// Code by https://stackoverflow.com/users/815724/peter-o

			BYTE keyState[256] = {0};
			//to unlock SetForegroundWindow we need to imitate Alt pressing
			if (GetKeyboardState((LPBYTE)&keyState))
			{
				if (!(keyState[VK_MENU] & 0x80))
				{
					::keybd_event(VK_MENU, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
				}
			}

			SetForegroundWindow(_handle);

			if (GetKeyboardState((LPBYTE)&keyState))
			{
				if (!(keyState[VK_MENU] & 0x80))
				{
					keybd_event(VK_MENU, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
				}
			}

			// Toggle top, remove it, set focus
			SetWindowPos(_handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
			SetWindowPos(_handle, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
			SetFocus(_handle);
		}
	}
}

HWND MainWindow::getRealParent(HWND hWnd)
{
	HWND hParent;

	hParent = GetAncestor(hWnd, GA_PARENT);
	if (!hParent || hParent == GetDesktopWindow())
		return NULL;

    return hParent;
}

void MainWindow::trayTriggered(QAction *action)
{
        if(action->text() == "quit")
            exit(0);

}

