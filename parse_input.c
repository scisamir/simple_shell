#include "shell.h"
/**
 * parse_input - function that tokenize the iput
 * string
 * @str: strings to be tokenize
 *
 * Return: tokenized string
 */

char **parse_input(char *str)
{
	char *word, **words, *str_copy;
	char *delim = " \n";
	int i = 0, words_len = 0;

	if (str)
		{
		str_copy = _strdup(str);
		word = strtok(str, delim);
		while (word)
		{
			words_len++;
			word = strtok(NULL, delim);
		}
		if (words_len == 0)
		{
			free(str_copy);
			return (NULL);
		}

		words = malloc(sizeof(char *) * (words_len + 1));
		if (words == NULL)
		{
			free(str_copy);
			return (NULL);
		}
		word = strtok(str_copy, delim);
		while (word)
		{
			words[i] = _strdup(word);
			word = strtok(NULL, delim);
			i++;
		}
		words[i] = NULL;
		free(str_copy);
		return (words);
	}
	return (NULL);
}
