#include "monty.h"

void m_nop(stack_t **stack, unsigned int line_number);
void m_pchar(stack_t **stack, unsigned int line_number);
void m_pstr(stack_t **stack, unsigned int line_number);

/**
 * m_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: pointer to top mode node
 * @line_number:current line number.
 * Return: None
 */
void m_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * m_pchar - prints top char value
 * @stack: pointer to top mode node
 * @line_number:current line number.
 * Return: None
 */
void m_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		err_op_tok(err_pchar(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		err_op_tok(err_pchar(line_number,
					     "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}

/**
 * m_pstr - prints a string.
 * @stack: pointer to top mode node
 * @line_number:current line number.
 * Return: None
 */
void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}
