#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: the string input / parameter
 *
 * Return: On success, the _strdup function returns a pointer to the
 * duplicated string. It returns NULL if insufficient memory was available
 * or if the input string is null
 */

char *_strdup(char *str)
{
	int len = 0;
	char *new_str;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;
	len += 1;
	new_str = malloc(len * sizeof(char));

	if (new_str == NULL)
		return (NULL);
	len = 0;

	while (str[len])
	{
		new_str[len] = str[len];
		len++;
	}
	new_str[len] = '\0';

	return (new_str);
}


/**
 * _strlen - returns the length of a string
 * @s: the string input
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
	if (*s)
		return (1 + _strlen(++s));
	return (0);
}


/**
 * _strcpy - copies the string pointed to by src, including the
 * terminating null byte (\0), to the buffer pointed to by dest
 * @dest: the destination
 * @src: the string to be copied
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		*(dest + i) = *(src + i);
	} while (*(src + i) != '\0');

	return (dest);
}


/**
 * _strcat - concatenates two strings
 * @dest: the string to be concatenated to
 * @src: the string to be concatenated
 *
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, dest_len, src_len;

	dest_len = _strlen(dest);
	src_len = _strlen(src);

	dest += dest_len;

	while (i < src_len)
	{
		*dest++ = src[i];
		i++;
	}

	*dest = '\0';

	return (dest);
}


/**
 * _strcmp - compares two strings
 * @s1: first string input
 * @s2: second string input
 *
 * Return: Returns a negative if s1 < s2, positive if s1 > s2 or
 * zero is s1 is equal to s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, res;

	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;

	res = s1[i] - s2[i];

	return (res);
}
