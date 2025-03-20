#include "ClipboardManager.h"
#include <algorithm>

ClipboardManager& ClipboardManager::getInstance() {
    static ClipboardManager instance;
    return instance;
}

bool ClipboardManager::readClipboard() {
    if (!OpenClipboard(nullptr)) return false;
    
    HANDLE hData = GetClipboardData(CF_UNICODETEXT);
    if (hData) {
        wchar_t* pszText = static_cast<wchar_t*>(GlobalLock(hData));
        if (pszText) {
            m_clipboardText = pszText;
            GlobalUnlock(hData);
        }
    }
    
    CloseClipboard();
    return !m_clipboardText.empty();
}

std::wstring ClipboardManager::getText() const {
    return m_clipboardText;
}