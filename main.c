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
			free(words[i]);
			i++;
		}
		free(words);
	}
}


/**
* _realloc -  reallocates a memory block using malloc and free
* @ptr: a pointer to the memory previously allocated with a call to
* malloc: malloc(old_size)
* @old_size: the size, in bytes, of the allocated space for ptr
* @new_size: the new size, in bytes of the new memory block
*
* Return: a pointer to the new allocated memory block or the old memory block
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, size = new_size;
	char *new_ptr;
	char *old_ptr = ptr;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (ptr == NULL)
		return (new_ptr);

	if (new_size > old_size)
		size = old_size;

	for (i = 0; i < size; i++)
		new_ptr[i] = *(old_ptr + i);

	free(old_ptr);
	return (new_ptr);
}


/**
 * main - Entry point to the shell program, "hsh"
 *
 * Return: On Success, EXIT_SUCCESS
 */

int main(void)
{
	char *prompt = "($) ", *newline = "\n", *lptr = NULL, **words = NULL;
	size_t n = 0;
	ssize_t check = 0;
	int mode, failed_exit = 0;

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
			{
				if (failed_exit && !words[1])
				{
					words = _realloc(words, sizeof(words), sizeof(char *) * 3);
					words[1] = _strdup("2"), words[2] = NULL;
				}
				free(lptr);
			}
			failed_exit = check_input(words);
		}
		free(lptr), free_words(words), fflush(stdin);
		lptr = NULL, words = NULL, n = 0, check = 0;
	}
	return (EXIT_SUCCESS);
}
