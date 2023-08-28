#include "monty.h"

void m_push(stack_t **stack, unsigned int line_number);
void m_pall(stack_t **stack, unsigned int line_number);
void m_pint(stack_t **stack, unsigned int line_number);
void m_pop(stack_t **stack, unsigned int line_number);
void m_swap(stack_t **stack, unsigned int line_number);

/**
 * m_push - pus sh function
 * @stack: this is the pointer to top
 * @line_number: current line
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		err_op_tok(err_malloc());
		return;
	}
	if (op_toks[1] == NULL)
	{
		err_op_tok(err_int(line_number));
		return;
	}
	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			err_op_tok(err_int(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);
	if (check_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * m_pall - this prnts the stack
 * @stack: this is the poniter to the top mode node.
 * @line_number: current line
 * Return: None
 */
void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * m_pint - this Prints the top value of a stack_t linked list.
 * @stack:this is the  poniter to the top mode node.
 * @line_number: current line*
 * Return: None
 */
void m_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		err_op_tok(err_pint(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * m_pop -this will  remove the top element
 * @stack: this is the poniter to the top mode node.
 * @line_number: current line*
 * Return: None
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nxt = NULL;

	if ((*stack)->next == NULL)
	{
		err_op_tok(err_pop(line_number));
		return;
	}

	nxt = (*stack)->next->next;
	free((*stack)->next);
	if (nxt)
		nxt->prev = *stack;
	(*stack)->next = nxt;
}

/**
 * m_swap - this is swaps top 2
 * @stack: this is the pointer to the top mode node.
 * @line_number: current line*
 * Return: None
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_op_tok(err_s_stack(line_number, "swap"));
		return;
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
