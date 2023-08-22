#include "shell.h"

/**
 * cd - cd command
 * @command: list of arguments with cd
 *
 * Return: 0 when successful
 */

int cd(char __attribute__((unused)) **command)
{
	char *home;

	if (command[2] != NULL)
	{
		printf("./hsh: cd: too many arguments\n");
		return (-1);
	}
	home = malloc(sizeof(char) * (strlen(getenv("HOME")) + 1));
	if (home == NULL)
	{
		perror("./hsh");
		return (-1);
	}

	home = strdup(getenv("HOME"));
	if (command[1] == NULL || !(strcmp(command[1], "~")))
	{
		ch_dir(home);
		return (0);
	}

	if (!(strcmp(command[1], "-")))
	{
		printf("%s\n", home);
		ch_dir(home);
		return (0);
	}

	ch_dir(command[1]);
	free(home);
	return (0);
}

/**
 * ch_dir - chdir function caller
 * @path: path to change to
 */

void ch_dir(char *path)
{
	int ch_stat;
	char *cur_dir = NULL, *temp_dir = NULL;
	size_t buff_size = 128;

	ch_stat = chdir(path);
	if (ch_stat != 0)
	{
		perror("./hsh: cd");
		return;
	}
	while (1)
	{
		if (realloc(temp_dir, buff_size * sizeof(char)) == NULL)
			perror("./hsh");
				return;
		getcwd(temp_dir, buff_size);
		if (temp_dir == NULL)
		{
			buff_size *= 2;
			continue;
		} else
			break;
	}
	cur_dir = malloc(sizeof(char) * (strlen(temp_dir) + 1));
	getcwd(cur_dir, (strlen(temp_dir) + 1));
	if (cur_dir == NULL)
	{
		perror("./hsh");
		return;
	}
	if ((setenv("PWD", cur_dir, 1)) != 0)
	{
		perror("./hsh");
		return;
	}
}


