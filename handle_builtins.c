#include "shell.h"

/**
 * handle_exit - funtion that handles "exit"
 * command
 * @args: an array of strings containing the argument
 * passed to the program
 *
 * Return: Exit Success
 */

int handle_exit(char **args)
{
	free_words(args);

	exit(EXIT_SUCCESS);
}

/**
 * handle_cd - function that handles "cd"
 * builtin command
 * @args: an array of strings containing the argument
 * passed to the program
 *
 * Return: Exit Success
 */

int handle_cd(char **args)
{
	if (!args[1])
		perror("Error");

	else
	{
		if (chdir(args[1]) == -1)
			perror("Error");
	}

	return (EXIT_SUCCESS);
}
