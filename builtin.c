#include "shell.h"

/**
 * builtin - checks if its a builtin
 * and calls the proper function
 * @command: command
 *
 * Return: 0 if builtin 1 if not
 */

int builtin(char **command)
{
	int i;
	bltin built_ins[] = {
		{"exit", exit_func},
		{"env", env},
		{"cd", cd},
		{NULL, NULL}
	};


	for (i = 0; built_ins[i].command != NULL; i++)
	{
		if (!(strcmp(built_ins[i].command, command[0])))
		{
			built_ins[i].func(command);
			return (0);
		}
	}
	return (1);
}
