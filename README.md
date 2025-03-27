# AutoPaste

## 概述

AutoPaste 是一个用 C++ 编写的项目，旨在实现使用系统级输出法API粘贴内容的功能。该项目可以帮助用户提高工作效率，特别是在无法粘贴的输入框中粘贴内容的场景下。

---

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

或者其实可以直接下载已经编译好的版本，双击或在命令行运行。

运行成功后，只需使用快捷键`Ctrl+M`即可调用系统级输出法API粘贴内容，即无视一切防粘贴功能（除非丧心病狂的禁用了输入法和键盘输入）。

## 注意事项

- 该项目仅适用于 Windows 操作系统。
- 编译需要CMake。

## 常见错误处理

1. 系统版本与编译环境差异过大，导致不兼容（开发者编译时使用了Win11）。
2. `Ctrl+M`快捷键冲突，快捷键已经被其他程序占用，会导致运行失败。
3. 没有切换英文输入模式可能会导致粘贴混乱，内在原理是模拟键盘输入时，其他输入法认为用户正在输入，导致其中ASCII字符无法正常粘贴。

> 偶然想到其实AP也可以用出键盘宏的效果。

---

## 未来与展望

预计加入如下功能：

1.1.0 支持自定义快捷键。

1.2.0 支持多快捷键。

1.3.0 支持自定义粘贴速度。

1.4.0 增加命令行指令

...

2.0.0 增加GUI界面。

2.1.0 允许自定义粘贴内容。

2.2.0 增加粘贴来自文件的内容。

2.3.0 增加粘贴来自网络的内容。

...

2.x.0 增加键盘宏功能。

...

2.y.0 增加开机自启，成为系统服务。

...

3.0.0 成为真正的输入法，同时兼容原先一切。

...

4.0.0 增加AI功能，一键粘贴AI生成的内容。

...

5.0.0 AI Agent全自动托管键盘。

...

5.x.0 AI Agent全自动托管鼠标。

...

6.0.0 AI Agent全自动托管计算机。

...
