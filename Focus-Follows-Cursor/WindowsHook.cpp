#include "WindowsHook.h"

LRESULT CALLBACK mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//     PMSLLHOOKSTRUCT p = (PMSLLHOOKSTRUCT) lParam;
     return CallNextHookEx(NULL, nCode, wParam, lParam);
}

WindowsHook::WindowsHook(QObject *parent) : QObject(parent)
{

}
