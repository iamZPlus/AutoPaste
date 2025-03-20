#include "InputSimulator.h"
#include <windows.h>

void InputSimulator::typeString(const std::wstring& str) {
    // 保存原始修饰键状态
    bool ctrlPressed = GetAsyncKeyState(VK_CONTROL) & 0x8000;
    bool altPressed = GetAsyncKeyState(VK_MENU) & 0x8000;
    bool shiftPressed = GetAsyncKeyState(VK_SHIFT) & 0x8000;

    // 释放所有修饰键
    if (ctrlPressed) {
        INPUT ctrlUp = {0};
        ctrlUp.type = INPUT_KEYBOARD;
        ctrlUp.ki.wVk = VK_CONTROL;
        ctrlUp.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ctrlUp, sizeof(INPUT));
    
}
    if (altPressed) {
        INPUT altUp = {0};
        altUp.type = INPUT_KEYBOARD;
        altUp.ki.wVk = VK_MENU;
        altUp.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &altUp, sizeof(INPUT));
    
}
    if (shiftPressed) {
        INPUT shiftUp = {0};
        shiftUp.type = INPUT_KEYBOARD;
        shiftUp.ki.wVk = VK_SHIFT;
        shiftUp.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &shiftUp, sizeof(INPUT));
    
}
    for (wchar_t c : str) {
        if (c <= 127) { // 处理ASCII字符
            SHORT vk = VkKeyScanW(c);
            BYTE vkCode = LOBYTE(vk);
            BYTE shiftState = HIBYTE(vk);

            // 处理shift键状态
            if (shiftState & 1) {
                INPUT shiftDown = {0};
                shiftDown.type = INPUT_KEYBOARD;
                shiftDown.ki.wVk = VK_SHIFT;
                SendInput(1, &shiftDown, sizeof(INPUT));
            
}

            // 发送按键按下
            INPUT keyDown = {0};
            keyDown.type = INPUT_KEYBOARD;
            keyDown.ki.wVk = vkCode;
            SendInput(1, &keyDown, sizeof(INPUT));

            // 发送按键释放
            INPUT keyUp = keyDown;
            keyUp.ki.dwFlags |= KEYEVENTF_KEYUP;
            SendInput(1, &keyUp, sizeof(INPUT));

            // 释放shift键
            if (shiftState & 1) {
                INPUT shiftUp = {0};
                shiftUp.type = INPUT_KEYBOARD;
                shiftUp.ki.wVk = VK_SHIFT;
                shiftUp.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &shiftUp, sizeof(INPUT));
            
}
        
} else { // 处理非ASCII字符
            INPUT input[2] = {0};
            
            input[0].type = INPUT_KEYBOARD;
            input[0].ki.wScan = c;
            input[0].ki.dwFlags = KEYEVENTF_UNICODE;
            
            input[1] = input[0];
            input[1].ki.dwFlags |= KEYEVENTF_KEYUP;
            
            SendInput(2, input, sizeof(INPUT));
        
}
    
}

}