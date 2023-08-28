
#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - this is the entry point
 * @argc: this is the args count
 * @argv: this is the pointer array of arguments
 * Return: success or fail
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (err_usage());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (err_fopen(argv[1]));
	exit_code = run_m(script_fd);
	fclose(script_fd);
	return (exit_code);
}
