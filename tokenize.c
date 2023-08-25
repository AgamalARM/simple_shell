#include "shell.h"
/**
 * tokenize - the function is separating each string with the delimiter
 * @data: the data pointer to code of data
 * Return: the array to a different elements of the string
 */
void tokenize(data_of_program *data)
{
	char *delimiter = " \t";     /*** define an char pointer ***/
	int i, j, counter = 2, length; /*** define variables ***/

	length = str_length(data->input_line);
	/*********  if statement       **********************/
	if (length)
	{
		if (data->input_line[length - 1] == '\n')
			data->input_line[length - 1] = '\0';
	}
	/*********  for statement       **********************/

	for (i = 0; data->input_line[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			/*********  if statement       **********************/
			if (data->input_line[i] == delimiter[j])
				counter++;     /**   define counter**/
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	/*********  if statement       **********************/
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	i = 0;
	data->tokens[i] = str_duplicate(_strtok(data->input_line, delimiter));
	data->command_name = str_duplicate(data->tokens[0]);
	/*********  while loop  statement       **********************/
	while (data->tokens[i++])
	{
		data->tokens[i] = str_duplicate(_strtok(NULL, delimiter));
	}
}
