#include <stdlib.h>


char *int_get(int num);
unsigned int _abs(int);
int _numbase_len(unsigned int num, unsigned int base);
void _numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/**
 * int_get - this gets *char from int
 * @num: this is the number 
 * Return: new string
 */
char *int_get(int num)
{
	unsigned int tmp;
	int len = 0;
	long num_l = 0;
	char *a;

	tmp = _abs(num);
	len = _numbase_len(tmp, 10);
	if (num < 0 || num_l < 0)
		len++;
	a = malloc(len + 1);
	if (!a)
		return (NULL);
	_numbase_buff(tmp, 10, a, len);
	if (num < 0 || num_l < 0)
		a[0] = '-';
	return (a);
}

/**
 * _abs - abs value of number
 * @i: integer 
 * Return: unsigned integer
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * _numbase_len - this gets size of int required
 * @num: this is the number
 * @base: this is the base of number
 * Return: length of buffer needed
 */
int _numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * _numbase_buff - this enters the number in buf
 * @num: This is the number 
 * @base: this is the base of number 
 * @buff: this is the buffer
 * @buff_size: this is size of buffer
 * Return: none
 */
void _numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int reminder;
	int i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		reminder = num % base;
		if (reminder > 9)
			buff[i] = reminder + 87;
		else
			buff[i] = reminder + '0';
		num /= base;
		i--;
	}
}
