#include "push_swap.h"

void	print_stack(char *name, t_stack *stack)
{
	t_node	*current;

	printf("%s: ", name);
	current = stack->top;
	while (current)
	{
		printf("%d", current->value);
		if (current->next)
			printf(" -> ");
		current = current->next;
	}
	printf("\nsize = %d\n\n", stack->size);
}