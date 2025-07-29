# 🖥️ Linux Shell

A custom Linux shell implemented in **C++** that supports command execution, history tracking, I/O redirection, piping, background execution, and more.  
This project is designed to simulate basic Linux shell functionality and improve understanding of process management, system calls, and command parsing.

---

## 🚀 Features
- **Basic Commands:** Supports standard commands like `ls`, `pwd`, `cd`, `cat`, etc.
- **Command History:** Tracks and displays previously executed commands.
- **I/O Redirection:** Supports `>` for output redirection and `<` for input redirection.
- **Piping:** Chain multiple commands using `|`.
- **Multiple Commands:** Run multiple commands separated by `;`.
- **Background Execution:** Run tasks in the background using `&`.
- **Custom Prompt:** Displays a clean custom prompt.

---

## 🛠️ Tech Stack
- **Language:** C++
- **Platform:** Linux (Kali/Ubuntu)
- **Tools:** GCC, Git, Shell commands

---

## ⚙️ Installation
1. Clone the repository:
   ```bash
   git clone git@github.com:Sudhir104/linux-shell.git
   cd linux-shell
g++ myshell.cpp -o myshell
./myshell
MyShell> pwd
/home/sudhir

MyShell> ls | grep .cpp
myshell.cpp

MyShell> sleep 5 &

MyShell> history
1  pwd
2  ls | grep .cpp
3  sleep 5 &
4  history

MyShell> exit
linux-shell/
│
├── myshell.cpp     # Main shell implementation file
├── README.md       # Project documentation
└── LICENSE         # License file (MIT)

---

### ✅ Next Steps:
MIT License

Copyright (c) 2025 Sudhir Mathur

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
  


