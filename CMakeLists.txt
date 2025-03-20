cmake_minimum_required(VERSION 3.15)
project(AutoPaste)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AutoPaste
    main.cpp
    ClipboardManager.cpp
    ClipboardManager.h
    HotkeyHandler.cpp
    HotkeyHandler.h
    InputSimulator.cpp
    InputSimulator.h
)

target_compile_definitions(AutoPaste PRIVATE UNICODE _UNICODE)
target_link_options(AutoPaste PRIVATE "/ENTRY:WinMainCRTStartup")

target_link_libraries(AutoPaste
    user32.lib
    gdi32.lib
    ole32.lib
)