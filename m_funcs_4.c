
#include "monty.h"

void m_rotl(stack_t **stack, unsigned int line_number);
void m_rotr(stack_t **stack, unsigned int line_number);
void m_stack(stack_t **stack, unsigned int line_number);
void m_queue(stack_t **stack, unsigned int line_number);

/**
 * m_rotl - rotates the top value to bottom
 * @stack: pointer to stack
 * @line_number: current line number
 * Return: None.
 */
void m_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
	(void)line_number;
}

/**
 * m_rotr - rorates bottom to top
 * @stack: pointer to stack
 * @line_number: current line number
 * Return: None.
 */
void m_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;
	(void)line_number;
}

/**
 * m_stack - converts a queue to a stack
 * @stack: pointer to stack
 * @line_number: current line number
 * Return: None.
 */
void m_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * m_queue - converts a stack to a queue.
 * @stack: pointer to stack
 * @line_number: current line number
 * Return: None.
 */
void m_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
