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
	int status;

	if (args)
	{
		if (!args[1])
		{
			free_words(args);
			exit(EXIT_SUCCESS);
		}

		status = atoi(args[1]);
		free_words(args);
		exit(status);
	}

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
	char *dir_new = args[1];
	char *dir_current;

	if (!dir_new)
	{
		dir_new = getenv("HOME");
		if (dir_new)
		{
			perror("Error");
			return (EXIT_FAILURE);
		}
	}
	else if (strcmp(dir_new, "-") == 0)
	{
		dir_new = getenv("OLDPWD");
		if (!dir_new)
		{
			perror("Error");
			return (EXIT_FAILURE);
		}
	}
	dir_current = getcwd(NULL, 0);
	if (!dir_current)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	free(dir_current);
	if (chdir(dir_new) == -1)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	setenv("PWD", dir_current, 1);
	free(dir_current);

	return (EXIT_SUCCESS);
}


/**
 * handle_env - function that handles "env"
 * builtin command
 * @args: an array of strings containing the argument
 * passed to the program
 *
 * Return: Exit Success
 */

int handle_env(__attribute__((unused)) char **args)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (EXIT_SUCCESS);
}
