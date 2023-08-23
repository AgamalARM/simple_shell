#include "shell.h"
/**
 * tok - tokenize the entire list of commands
 * @com: command
 *
 * Return: tokenized command
 */

char **tok(char *com)
{
	char **args;
	size_t arg_count = 0, i;
	char  *delim = "\n", *token, *cmd_dup;

	cmd_dup = malloc(sizeof(char) * (strlen(com) + 1));
	cmd_dup = strdup(com);
	token = strtok(com, delim);

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

/**
 * loopREP - for non interactive mode
 * @paths: path
 * @command: command
 *
 * Return: o on success
 */

int loopREP(char *paths, char *command)
{
	char **args = NULL;
	char *temp_comm = NULL;
	int builtin_check;

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
	fprintf(stderr, "./hsh: 1: %s: not found\n", command);
		exit(127);
	}
	if (exec_command(args) == -1)
		exit(errno);

	free(temp_comm);
	return (0);
}
/**
 * loop - keeps the REP process in loop
 */
void loop(void)
{
	char *path, **commands, *com;
	size_t i = 0, len;

	path = getenv("PATH");
	if (isatty(STDIN_FILENO) == 0)
	{
		getdelim(&com, &len, '\0', stdin);
		commands = tok(com);
		while (commands[i])
		{
			loopREP(path, commands[i]);
			i++;
		}
	} else
	{
		while (1)
		{
			printf("$ ");
			REP(path);
		}
	}
}
