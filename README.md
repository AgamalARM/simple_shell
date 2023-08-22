# Shell Project


This is a simple shell project that handles simple arguments, works in interactive and non-interactive modes, handles the path, and includes the built-in commands exit and env.


## Features

- Executes commands with arguments
- Supports interactive and non-interactive modes
- Handles the PATH environment variable
- Includes built-in commands "exit" and "env"


## Getting Started

To get started with this shell project, you can follow the steps below:


### Prerequisites

You need to have a C compiler like `gcc` installed on your system.

## Usage

The shell handles simple commands and their arguments. To execute a command, simply type it in the shell prompt.

### Interactive Mode

In interactive mode, the shell prompts the user for input continuously until the user explicitly exits.



$ ./shell
>> ls
file1.txt  file2.txt  folder1
>> pwd
/home/user
>> exit
$

### Non-Interactive Mode

In non-interactive mode, the shell reads commands from a file and executes them accordingly. The output will be displayed on the console.



$ ./shell < commands.txt
file1.txt  file2.txt  folder1
/home/user
$

### Built-in Commands

The shell includes two built-in commands: `exit` and `env`.

- `exit`: Terminates the shell and returns to the parent shell.
- `env`: Prints out the current environment variables.



$ ./shell
>> env
USER=your_username
HOME=/home/user
...
>> exit
$

## Contributers
Ahmed Gamal: bavlyatef099@gmail.com
Ismael Muzemil: ismael.mdev@gmai.com
