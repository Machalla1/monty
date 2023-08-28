#include "monty.h"

void m_add(stack_t **stack, unsigned int line_number);
void m_sub(stack_t **stack, unsigned int line_number);
void m_div(stack_t **stack, unsigned int line_number);
void m_mul(stack_t **stack, unsigned int line_number);
void m_mod(stack_t **stack, unsigned int line_number);

/**
 * m_add - this add the top 2 elements
 * @stack: this is the pointer to top mode node
 * @line_number: current line number
 * Return: None
 */
void m_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_op_tok(err_s_stack(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	m_pop(stack, line_number);
}

/**
 * m_sub - this subtracts the top 2 elements
 * @stack: this is the pointer to top mode node
 * @line_number: current line number
 * Return: None
 */
void m_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_op_tok(err_s_stack(line_number, "sub"));
		return;
	}
	(*stack)->next->next->n -= (*stack)->next->n;
	m_pop(stack, line_number);
}

/**
 * m_div - this div the top 2 numbers
 * @stack: this is the pointer to top mode node
 * @line_number: current line number
 * Return: None
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_op_tok(err_s_stack(line_number, "div"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		err_op_tok(err_div(line_number));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	m_pop(stack, line_number);
}

/**
 * m_mul - this multiplies the top 2
 * @stack: this is the pointer to top mode node
 * @line_number: current line number
 * Return: None.
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_op_tok(err_s_stack(line_number, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	m_pop(stack, line_number);
}

/**
 * m_mod - this is modulus of the two
 * @stack: this is the pointer to top mode node
 * @line_number: current line number
 * Return: None
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_op_tok(err_s_stack(line_number, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		err_op_tok(err_div(line_number));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	m_pop(stack, line_number);
}
