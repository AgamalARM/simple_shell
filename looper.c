#include "shell.h"

/**
 * loop - keeps the REP process in loop
 */

void loop(void)
{
	char *path;

	path = getenv("PATH");
	while (1)
	{
		printf("$ ");
		REP(path);
	}
}
