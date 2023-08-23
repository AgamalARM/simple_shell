#include "shell.h"

/**
 * exec_command - executes command
 * @args: array containing arguments and pathname
 *
 * Return: 0 on success -1 otherwise
 */

int exec_command(char **args)
{
	int exec_stat;
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("./hsh");
		return (-1);
	}
	if (pid == 0)
	{
		exec_stat = execve(args[0], args, environ);
		if (exec_stat == -1)
		{
			free(args);
			perror("./hsh");
			return (errno);
		}
	} else
	{
		wait(NULL);
		free(args);
		return (0);
	}
	return (0);
}
