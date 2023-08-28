#include "monty.h"


/**
 * err_pop -  this empty stac k pop error message
 * @line_number: this is the current line.
 * Return: Failure
 */
int err_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * err_pint -this is an empty stack error for pint
 * @line_number: this is the current line
 * Return: Failure
 */
int err_pint(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * err_s_stack - this is the short stack error message
 * @line_number: this is the current line.
 * @op: current operation
 * Return: Failure
 */
int err_s_stack(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * err_div - this is div error message
 * @line_number: Current line number
 * Return: Failure
 */
int err_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * err_pchar - this is the char error messages 
 * @line_number: current line number
 * @message: the message
 * Return: Failure
 */
int err_pchar(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
