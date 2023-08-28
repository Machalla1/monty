
#include <stdlib.h>

char **strtow(char *str, char *delims);
int _delim(char ch, char *delims);
int word_length(char *str, char *delims);
int word_count(char *str, char *delims);
char *next_word(char *str, char *delims);

/**
 * str_w - this tokenizes a string.
 * @str: this is the string to tokenize
 * @delims: delimitors to use
 * Return: array after tokenization
 */

char **str_w(char *str, char *delims)
{
	char **words = NULL;
	int wordc, wordl, n;
	int i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wordc = word_count(str, delims);
	if (wordc == 0)
		return (NULL);
	words = malloc((wordc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wordc)
	{
		wordl = word_length(str, delims);
		if (_delim(*str, delims))
		{
			str = next_word(str, delims);
		}
		words[i] = malloc((wordl + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordl)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * _delim -this checks for delim
 * @ch: character
 * @delims: delimitors
 * Return: 1 or 0
 */

int _delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * word_length - this finds current word length
 * @str: this is the string
 * @delims: this is delimitors
 * Return: word length
 */

int word_length(char *str, char *delims)
{
	int wlen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wlen++;
		}
		if (wlen > 0 && _delim(str[i], delims))
			break;
		i++;
	}
	return (wlen);
}

/**
 * word_count - this gets the word count of a string
 * @str: this is the string
 * @delims: delimitors
 * Return: word count
 */

int word_count(char *str, char *delims)
{
	int wordc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wordc++;
		}
		i++;
	}
	return (wordc);
}

/**
 * next_word - this moves to the next word
 * @str: this is the string 
 * @delims: delimitors
 * Return: pointer to next word
 */

char *next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
