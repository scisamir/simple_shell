#include "shell.h"

/**
 * free_words - frees the array of strings of the input to the terminal
 * @words: the array of strings to be freed
 *
 * Return: Nothing
 */

void free_words(char **words)
{
	int i = 0;

	if (words)
	{
		while (words[i])
		{
			if (words[i])
				free(words[i]);
			i++;
		}
		if (words)
			free(words);
	}
}


/**
 * main - Entry point to the shell program, "hsh"
 *
 * Return: On Success, EXIT_SUCCESS
 */

int main(void)
{
	char *prompt = "($) ", *newline = "\n";
	char *lptr = NULL, **words = NULL;
	size_t n = 0;
	ssize_t check = 0;
	int mode;

	while (check != -1)
	{
		mode = isatty(STDIN_FILENO);
		if (mode)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		check = getline(&lptr, &n, stdin);

		if (check == -1)
		{
			if (lptr)
				free(lptr);
			handle_exit(words);
		}
		if (lptr && _strcmp(lptr, newline))
			words = parse_input(lptr);
		if (words)
		{
			if (!(_strcmp(words[0], "exit")))
				free(lptr);
			check_input(words);
		}

		free(lptr);
		free_words(words);
		fflush(stdin);
		lptr = NULL, words = NULL;
		n = 0, check = 0;
	}

	return (EXIT_SUCCESS);
}
