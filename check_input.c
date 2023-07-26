#include "shell.h"

/**
 * check_input - Checks the input to the shell program and executes
 * the command passed
 * @args: an array of strings containing the arguments passed to the program
 *
 * Return: The return value of the function it calls
 */

int check_input(char **args)
{
	unsigned int i;
	builtin_t builtin_arr[] = {
		{"cd", handle_cd},
		{"exit", handle_exit},
		{NULL, NULL},
	};

	for (i = 0; builtin_arr[i].cmnd; i++)
	{
		if (!(_strcmp(builtin_arr[i].cmnd, args[0])))
			return ((builtin_arr[i].f)(args));
	}

	return (handle_execs(args));
}
