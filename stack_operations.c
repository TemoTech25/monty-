#include "monty.h"

/**
 * push_stack - Push a new element onto the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to be pushed onto the stack
 */
void push_stack(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * free_stack - Free all elements in the stack
 * @stack: Double pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}

