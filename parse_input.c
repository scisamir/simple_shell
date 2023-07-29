#include "shell.h"
/**
 * get_input_count - function that returns the number of tokens
 * @str: strings to be tokenize
 * @delim: a delimiter to be passed to strtok
 *
 * Return: the length of the tokens
 */

int get_input_count(char *str, char *delim)
{
	char *word;
	int len = 0;

	word = strtok(str, delim);
	while (word)
	{
		if (word[0] == '#')
			break;
		len++;
		word = strtok(NULL, delim);
	}

	return (len);
}


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
		words_len = get_input_count(str, delim);
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
			if (word[0] == '#')
				break;
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
