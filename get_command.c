#include "shell.h"

/**
 * get_command - retrieves command from
 * the standard input
 *
 * Return: the command retrieved
 */

char *get_command(void)
{
	char *command = NULL;
	size_t len;

	if (getline(&command, &len, stdin) == -1)
	{
		fflush(stdin);
		exit(EXIT_SUCCESS);
	}
	return (command);
}
