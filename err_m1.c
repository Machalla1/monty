#include "monty.h"

int err_usage(void);
int err_message(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * err_usage - this is usage error massage
 * Return: Failure
 */
int err_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * err_malloc - usage error massage
 * Return: Failure
 */
int err_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * err_fopen - this will open file error massage
 * @filename: this is the pointer to file
 * Return: Failure
 */
int err_fopen(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * err_unknown_op - this prints unknown instruction error messages.
 * @opcode: this is the opcode where error occurred
 * @line_number: line where error occurred
 * Return: Failure
 */
int err_unknown_op(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * err_int - this is the invalid m_push  error message.
 * @line_number: this is the line number
 * Return: Failure
 */
int err_int(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
