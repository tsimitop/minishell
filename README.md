# Minishell

Minishell is a simplified Unix shell implemented in C. It supports basic shell features including command parsing, built-in commands, environment variable handling, input/output redirections, and pipelines. This is the first 42 team project. We worked together with [Yun](https://github.com/unow0517) while navigating git as a team for the first time.

## 📚 Project Overview

The goal of Minishell is to recreate a minimal shell environment while gaining a deep understanding of process creation, file descriptors, terminal behavior, and command execution in Unix-like systems.

## 🚀 Features

- Execution of binary and built-in commands
- `cd`, `echo`, `pwd`, `export`, `unset`, `env`, and `exit` built-in commands
- Input/output redirection (`>`, `>>`, `<`)
- Piping with `|`
- Environment variable expansion (`$VAR`)
- Proper handling of quotes and escapes
- Exit status management
- Signal handling (`CTRL-C`, `CTRL-\`, `CTRL-D`)
- Error messages and memory management

## 🛠️ How to Build

```bash
git clone https://github.com/tsimitop/minishell.git
cd minishell
make
```
## 🛠️ How to Run

```bash
./minishell
```
Test our minishell with any commands, builtins and redirections you like.
"\",   ";",   "&&"   and   "||" were not implemented.
