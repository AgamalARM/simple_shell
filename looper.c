#include "shell.h"

/**
 * loop - keeps the REP process in loop
 */

void loop(void)
{
	char *path;

	path = getenv("PATH");
	if (isatty(STDIN_FILENO) == 0)
	{
		REP(path);
	} else
	{
		while (1)
		{
			printf("$ ");
			REP(path);
		}
	}
}
