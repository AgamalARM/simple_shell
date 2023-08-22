#ifndef SHELL_H
#define SHELL_H
#define BUFFER_SIZE 128
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>

/**
 * struct built_in - builtin commands and
 * their functions
 *
 * @command: builting command
 * @func: correspodnding function
 */
struct built_in
{
	char *command;
	int (*func)(char __attribute__((unused)) **command);
};

/**
 * bltin - typedef builtin
 */
typedef struct built_in bltin;

extern char **environ;
int exec_command(char **args);
int ret_command(char **args);
char *get_command(void);
void loop(void);
int REP(char *paths);
char **tokenize(char *command);
int env(char __attribute__((unused)) **command);
int builtin(char **command);
int exit_func(char __attribute__((unused)) **command);
int cd(char __attribute__((unused)) **command);
void ch_dir(char *path);
char *path(char *command, char *path);
#endif
