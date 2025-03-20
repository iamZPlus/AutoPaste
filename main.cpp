#include <windows.h>
#include "HotkeyHandler.h"
#include "ClipboardManager.h"
#include "InputSimulator.h"
#include "FloatingWindow.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_HOTKEY:
            if (wParam == 1) {
                ClipboardManager::getInstance().readClipboard();
                std::wstring text = ClipboardManager::getInstance().getText();
                InputSimulator::typeString(text);
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"AutoPasteInputMethod";

    if (!RegisterClassEx(&wc)) return 1;

    HWND hWnd = CreateWindowEx(
        0,
        L"AutoPasteInputMethod",
        L"Auto Paste",
        0, 0, 0, 0, 0,
        nullptr, nullptr, hInstance, nullptr
    );

    if (!RegisterHotKey(hWnd, 1, MOD_CONTROL, 0x4D))  // Ctrl+M
        return 2;

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}