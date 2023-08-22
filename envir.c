#include "shell.h"

/**
 * env - prints the current environment
 * @command: unused varaible
 *
 * Return: 0 on success
 */

int env(char __attribute__((unused)) **command)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
