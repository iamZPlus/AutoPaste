#include "InputSimulator.h"
#include <windows.h>

void InputSimulator::typeString(const std::wstring& str) {
    INPUT input[2] = {0};
    
    for (wchar_t c : str) {
        // 设置Unicode键盘输入
        input[0].type = INPUT_KEYBOARD;
        input[0].ki.wScan = c;
        input[0].ki.dwFlags = KEYEVENTF_UNICODE;
        
        // 设置按键释放
        input[1] = input[0];
        input[1].ki.dwFlags |= KEYEVENTF_KEYUP;
        
        SendInput(2, input, sizeof(INPUT));
    }
}