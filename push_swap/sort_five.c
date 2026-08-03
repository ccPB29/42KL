/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 23:40:24 by luli2             #+#    #+#             */
/*   Updated: 2026/08/03 12:50:09 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		i;

	cur = a->top;
	min = cur->index;
	pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->index < min)
		{
			min = cur->index;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

static void	move_to_top(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos--)
			ra(a);
	}
	else
	{
		pos = a->size - pos;
		while (pos--)
			rra(a);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		move_to_top(a, find_min_pos(a));
		pb(a, b);
	}
	sort_three(a);
	while (b->size)
		pa(a, b);
}
