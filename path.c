#include "shell.h"

/**
 * path - adds path functionality
 * @command: command to be checked
 * @path: string containing the path variable
 *
 * Return: the full path of command
 */

char *path(char *command, char *path)
{
	int i = 0, j = 0;
	char  *token = NULL, **pathlist = NULL, *delim = ":", *temp_path;
	struct stat fstat;

	if (command == NULL)
		return (NULL);
	if (stat(command, &fstat) == 0)
		return (command);
	while (path[i])
		if (path[i++] == ':')
			j++;
	pathlist = malloc(sizeof(char *) * (j + 2));
	if (pathlist == NULL)
	{
		perror("./hsh");
		return (NULL);
	}
	i = 0;
	temp_path = malloc(sizeof(char) * (strlen(path + 1)));
	temp_path = strdup(path);
	token = strtok(temp_path, delim);
	while (token)
	{
		pathlist[i] = malloc(sizeof(char) * (strlen(token) + strlen(command) + 2));
		strcpy(pathlist[i], token);
		strcat(pathlist[i], "/");
		token = strtok(NULL, delim);
		i++;
	}
	pathlist[i] = NULL;
	i = 0;
	while (pathlist[i])
	{
		strcat(pathlist[i], command);
		if (stat(pathlist[i], &fstat) == 0)
			return (pathlist[i]);
		i++;
	}
	free(temp_path);
	return (NULL);
}
