#include "monty.h"

/**
 * get_opcode - gets the function for the opcode
 * @code: opcode given
 *
 * Return: function pointer
 */

void (*get_opcode(char *code))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, code) == 0)
			break;
	}
	return (instruct[i].f);
}
