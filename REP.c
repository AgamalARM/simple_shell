#include "shell.h"

/**
 * REP - read evaluate and print function
 * @paths: string containing the path variable
 *
 * Return: 0 on success
 */

int REP(char *paths)
{
	char **args = NULL;
	char *command = NULL, *temp_comm = NULL;
	int builtin_check;

	command = get_command();
	args = tokenize(command);
	if (args[0] == NULL)
		return (0);

	temp_comm = malloc(sizeof(char) * strlen(args[0]) + 1);
	if (temp_comm == NULL)
	{
		perror("./hsh");
		return (-1);
	}
	temp_comm = strdup(args[0]);
	builtin_check = builtin(args);
	if (builtin_check == 0)
		return (0);

	args[0] = path(temp_comm, paths);
	if (args[0] == NULL)
	{
		printf("%s: command not found\n", command);
		return (-1);
	}
	exec_command(args);
	free(temp_comm);
	return (0);
}
