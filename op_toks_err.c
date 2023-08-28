#include "monty.h"

/**
 * err_op_tok_err - this is the sets the last element of global var to error
 * @error_code: this is the integer to store as a string
 */
void err_op_tok(int error_code)
{
	int t_len = 0, i = 0;
	char *exit_string = NULL;
	char **new_toks = NULL;

	t_len = token_len();
	new_toks = malloc(sizeof(char *) * (t_len + 2));
	if (!op_toks)
	{
		err_malloc();
		return;
	}
	while (i < t_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_string = int_get(error_code);
	if (!exit_string)
	{
		free(new_toks);
		err_malloc();
		return;
	}
	new_toks[i++] = exit_string;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
