#include "shell.h"

/**
 * tokenize - tokenizes the command
 * as arguments into an array
 * @command: command to be tokenzed
 *
 * Return: the array of arguments that
 * are tokenized
 */
char **tokenize(char *command)
{
	char **args;
	size_t arg_count = 0, i;
	char  *delim = " \n\t", *token, *cmd_dup;

	cmd_dup = malloc(sizeof(char) * (strlen(command) + 1));
	cmd_dup = strdup(command);
	token = strtok(command, delim);

	while (token)
	{
		token = strtok(NULL, delim);
		arg_count++;
	}

	args = malloc(sizeof(char *) * (arg_count + 1));
	if (args == NULL)
	{
		perror("./hsh");
		return (NULL);
	}

	token = strtok(cmd_dup, delim);
	i = 0;
	while (token)
	{
		args[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;
	return (args);
}
