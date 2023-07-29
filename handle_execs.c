#include "shell.h"

/**
 * handle_execs - Handles executable arguments passed to the program
 * @args: an array of strings containing the arguments passed to the program
 *
 * Return: EXIT_SUCCESS on success, otherwise EXIT_FAILURE
 */

int handle_execs(char **args)
{
	int status;
	pid_t pid;
	char *path;

	path = find_path(args[0]);
	if (path == NULL)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
			perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("Error");
	else
	{
		wait(&status);
		free(path);
		path = NULL;

		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (EXIT_SUCCESS);
}
