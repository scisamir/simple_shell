#include "shell.h"

/**
 * find_exec - Checks if a command exists in "PATH" or it's an executable
 * @arg: The command passed
 *
 * Return: The executable's absolute path, or NULL if it's not found or an
 * error occured
 */

char *find_exec(char *arg)
{
	struct stat st;
	char *dir, *dir_pos, *path, *path_cp;
	int cmd_len, dir_len;

	path = getenv("PATH");
	if (path)
	{
		cmd_len = _strlen(arg);
		path_cp = _strdup(path);

		dir = strtok(path_cp, ":");
		while (dir)
		{
			dir_len = _strlen(dir);
			dir_pos = malloc(sizeof(char) * (cmd_len + dir_len + 2));
			if (dir_pos == NULL)
			{
				free(path_cp);
				return (NULL);
			}
			_strcpy(dir_pos, dir);
			dir_pos[(_strlen(dir_pos) + 1)] = '\0';
			_strcat(dir_pos, "/");
			_strcat(dir_pos, arg);
			_strcat(dir_pos, "\0");

			if (stat(dir_pos, &st) == 0)
			{
				free(path_cp);
				return (dir_pos);
			}
			free(dir_pos);
			dir = strtok(NULL, ":");
		}
		free(path_cp);
	}
	return (NULL);
}


/**
 * find_path - Checks if a command exists in "PATH" or it's an executable
 * @cmd: The command passed
 *
 * Return: The executable's absolute path, or NULL if it's not found or an
 * error occured
 */

char *find_path(char *cmd)
{
	struct stat st;
	char *cmd_cp, *exec;

	exec = find_exec(cmd);

	if (exec == NULL)
	{
		cmd_cp = _strdup(cmd);

		if (stat(cmd_cp, &st) == 0)
			return (cmd_cp);

		free(cmd_cp);
		return (NULL);
	}

	return (exec);
}
