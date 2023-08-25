#include "shell.h"
/**
 * _strtok - this is a separate strings with the delimiters
 * @line: the pointer to array that is received in the getline.
 * @delim: the characters that mark off string in parts.
 * Return: the pointer to that is  created tokens
*/
char *_strtok(char *line, char *delim)
{
	int j;    /*********  define variables       **********************/
	static char *str;  /*********  define variables       **********************/
	char *copystr;     /*********  define variables       **********************/
	
     /*********  if statement       **********************/
	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			break;
		}
		/*********  if statement       **********************/
		if (delim[j] == '\0')
			break;
	}
	copystr = str;
	/*********  if statement       **********************/
	if (*copystr == '\0')
		return (NULL);
	/*********  for statement       **********************/
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			/*********  if statement       **********************/
			if (*str == delim[j])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
