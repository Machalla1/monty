#include "monty.h"
#include <string.h>

void free_t(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_t -this  freees the tokens
 */
void free_t(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;
	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);
	free(op_toks);
}

/**
 * token_len - this gets the global var length
 * Return: the length
 */
unsigned int token_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * _empty_line - this checks the line from getline if it only has delimers.
 * @line:this is  the line
 * @delims:this is delimiter
 * Return:1 or 0
 */
int _empty_line(char *line, char *delims)
{
	int i;
	int j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}

/**
 * _op_func - this gets the appropriate function
 * @opcode: this is the opcode
 * Return: this is the pointer to function
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"stack", m_stack},
		{"queue", m_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}

/**
 * run_m - this execute monty file
 * @script_fd: this is the file descriptor for the monty file
 * Return: success or failure
 */
int run_m(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_s(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = str_w(line, DELIMS);
		if (op_toks == NULL)
		{
			if (_empty_line(line, DELIMS))
				continue;
			free_s(&stack);
			return (err_malloc());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			free_t();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_s(&stack);
			exit_status = err_unknown_op(op_toks[0], line_number);
			free_t();
			break;
		}
		prev_tok_len = token_len();
		op_func(&stack, line_number);
		if (token_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_t();
			break;
		}
		free_t();
	}
	free_s(&stack);
	if (line && *line == 0)
	{
		free(line);
		return (err_malloc());
	}
	free(line);
	return (exit_status);
}
