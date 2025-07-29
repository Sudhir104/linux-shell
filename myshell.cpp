#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <vector>
#include <fcntl.h>
#include <signal.h>
using namespace std;

void signalHandler(int signum) {
    cout << "\nMyShell> ";
    fflush(stdout);
}

void parseCommand(string &input, vector<char*> &args) {
    while (!input.empty() && input.front() == ' ') input.erase(input.begin());
    while (!input.empty() && input.back() == ' ') input.pop_back();

    if (input.empty()) return;

    string temp = input;
    char *token = strtok(&temp[0], " ");
    while (token != NULL) {
        args.push_back(strdup(token));
        token = strtok(NULL, " ");
    }
    args.push_back(NULL);
}

void executeSingleCommand(vector<char*> &args, bool background) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args.data());
        perror("exec failed");
        exit(1);
    } else if (pid > 0) {
        if (!background) wait(NULL);
    } else {
        cerr << "Fork failed!" << endl;
    }
}

void executePiping(vector<string> &commands) {
    int fd[2], in = 0;

    for (size_t i = 0; i < commands.size(); i++) {
        pipe(fd);
        pid_t pid = fork();

        if (pid == 0) {
            dup2(in, 0);
            if (i < commands.size() - 1) dup2(fd[1], 1);
            close(fd[0]);

            vector<char*> args;
            parseCommand(commands[i], args);
            execvp(args[0], args.data());
            perror("exec failed");
            exit(1);
        } else {
            wait(NULL);
            close(fd[1]);
            in = fd[0];
        }
    }
}

int main() {
    signal(SIGINT, signalHandler);
    string input;
    vector<string> history;

    while (true) {
        cout << "\033[1;32mMyShell>\033[0m "; // Green prompt
        getline(cin, input);

        if (input == "exit") break;
        if (input.empty()) continue;

        history.push_back(input);

        if (input == "history") {
            for (size_t i = 0; i < history.size(); i++)
                cout << i + 1 << "  " << history[i] << endl;
            continue;
        }

        // Split multiple commands (;)
        size_t pos;
        while ((pos = input.find(';')) != string::npos) {
            string cmd = input.substr(0, pos);
            input.erase(0, pos + 1);

            vector<char*> args;
            parseCommand(cmd, args);
            if (!args.empty()) executeSingleCommand(args, false);
        }

        // Check for piping
        vector<string> pipedCommands;
        size_t pipePos;
        string tempInput = input;
        while ((pipePos = tempInput.find('|')) != string::npos) {
            pipedCommands.push_back(tempInput.substr(0, pipePos));
            tempInput.erase(0, pipePos + 1);
        }
        pipedCommands.push_back(tempInput);

        if (pipedCommands.size() > 1) {
            executePiping(pipedCommands);
            continue;
        }

        // Background execution check
        bool background = false;
        if (input.back() == '&') {
            background = true;
            input.pop_back();
        }

        vector<char*> args;
        parseCommand(input, args);

        if (args.empty()) continue;

        // Handle cd
        if (strcmp(args[0], "cd") == 0) {
            const char* path = args[1] ? args[1] : getenv("HOME");
            if (chdir(path) != 0) perror("cd failed");
            continue;
        }

        executeSingleCommand(args, background);
    }
    return 0;
}
