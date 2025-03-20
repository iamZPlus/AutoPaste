#pragma once
#include <windows.h>
#include <string>

class ClipboardManager {
public:
    static ClipboardManager& getInstance();
    bool readClipboard();
    std::wstring getText() const;

private:
    ClipboardManager() = default;
    std::wstring m_clipboardText;
};