#include "ClipboardManager.h"
#include <algorithm>

ClipboardManager& ClipboardManager::getInstance() {
    static ClipboardManager instance;
    return instance;
}

bool ClipboardManager::readClipboard() {
    if (!OpenClipboard(nullptr)) return false;
    
    // 同时支持UNICODE和ANSI格式
    HANDLE hUnicode = GetClipboardData(CF_UNICODETEXT);
    HANDLE hAnsi = GetClipboardData(CF_TEXT);

    if (hUnicode) {
        wchar_t* pszText = static_cast<wchar_t*>(GlobalLock(hUnicode));
        if (pszText) {
            m_clipboardText = pszText;
            GlobalUnlock(hUnicode);
        }
    }
    else if (hAnsi) {
        char* pszText = static_cast<char*>(GlobalLock(hAnsi));
        if (pszText) {
            int length = MultiByteToWideChar(CP_ACP, 0, pszText, -1, NULL, 0);
            wchar_t* wideText = new wchar_t[length];
            MultiByteToWideChar(CP_ACP, 0, pszText, -1, wideText, length);
            m_clipboardText = wideText;
            delete[] wideText;
            GlobalUnlock(hAnsi);
        }
    }
    
    CloseClipboard();
    return !m_clipboardText.empty();
}

std::wstring ClipboardManager::getText() const {
    return m_clipboardText;
}