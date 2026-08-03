/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 12:51:12 by luli2             #+#    #+#             */
/*   Updated: 2026/08/03 12:51:29 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
