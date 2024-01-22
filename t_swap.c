#include "monty.h"

/**
 * t_swap - swaps the top two elements of the stack
 * @stack: pointer to top of the stack
 * @line_number: line no. of the opcode
*/

void t_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next != NULL)

	temp->next->prev = *stack;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
