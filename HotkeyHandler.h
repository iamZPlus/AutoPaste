#pragma once
#include <windows.h>

class HotkeyHandler {
public:
    static bool registerHotKey(HWND hWnd, int id, UINT fsModifiers, UINT vk);
    static void unregisterHotKey(HWND hWnd, int id);
};