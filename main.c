#include "monty.h"

/**
 * check_input - checks if the file exists
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */

FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry Point
 * argc: number of arguements
 * argv: arguement vector
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	char * nlines;
	char *lines[2] = {NULL, NULL};
	char *buf = NULL;
	int cont = 1;
	stack_t **head = NULL;

	fd = check_input(argc, argv);
	nlines = fgets(buf, size, fd);
	while (nlines != NULL)
	{
		lines[0] = strtok(buf, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", cont);
				fprintf(stderr, "unknown instruction %s\n", lines[0]);
				free(buf);
				exit(EXIT_FAILURE);
			}
			arg_t.arg = strtok(NULL, " \t\n");
			f(head, cont);
		}
		nlines = fgets(buf, size, fd);
		cont++;
	}

	free(buf);

	return (0);
}
