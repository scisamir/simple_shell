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

		if (status <= 0)
		{
			perror("Error");
			free_words(args);
			exit(2);
		}
		else
		{
			free_words(args);
			exit(status);
		}
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
	char cur_wd[PATH_MAX];
	int err = 1;

	if (!args[1])
		err = chdir(getenv("HOME"));

	else if (!(_strcmp(args[1], "-")))
		err = chdir(getenv("OLDPWD"));

	else
		err = chdir(args[1]);

	if (err)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	else if (!err)
	{
		getcwd(cur_wd, sizeof(cur_wd));
		setenv("OLD_PWD", getenv("PWD"), 1);
		setenv("PWD", cur_wd, 1);
	}

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
