#include "HotkeyHandler.h"
#include <windows.h>

bool HotkeyHandler::registerHotKey(HWND hWnd, int id, UINT fsModifiers, UINT vk) {
    return RegisterHotKey(hWnd, id, fsModifiers, vk);
}

void HotkeyHandler::unregisterHotKey(HWND hWnd, int id) {
    UnregisterHotKey(hWnd, id);
}