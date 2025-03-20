# AutoPaste

## 概述
AutoPaste 是一个用 C++ 编写的项目，旨在实现使用系统级输出法API粘贴内容的功能。该项目可以帮助用户提高工作效率，特别是在无法粘贴的输入框中粘贴内容的场景下。

## 安装与使用
### 安装
1. 克隆项目到本地：
   ```bash
   git clone https://github.com/iamZplus/AutoPaste.git
   cd AutoPaste
   ```
2. 编译项目：
   ```bash
   mkdir build
   cd build
   cmake -G"Visual Studio 17 2022" ..
   cd ..
   cmake --build build --config Release
   ```

### 使用
运行编译后的可执行文件：
```bash
build\Release\AutoPaste
```