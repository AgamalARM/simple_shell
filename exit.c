#include "shell.h"

/**
 * exit_func - exits program
 * @command: exit command with arguments
 *
 * Return: status specified or 0 when not given
 */

int exit_func(char __attribute__((unused)) **command)
{
	int stat;
	char *status;

	if (command[1] == NULL)
		exit(0);

	if (command[2] != NULL)
	{
		printf("./hsh: exit: too many arguments\n");
		return (-1);
	}
	status = malloc(sizeof(char) * (strlen(command[1]) + 1));
	if (status == NULL)
	{
		perror("./hsh");
		return (-1);
	}
	status = strdup(command[1]);
	stat = atoi(status);
	exit(stat);
}
