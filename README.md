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


