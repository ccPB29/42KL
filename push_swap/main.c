/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:08:02 by luli2             #+#    #+#             */
/*   Updated: 2026/08/04 11:58:51 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}

void	assign_index(t_stack *stack)
{
	t_node	*current;
	t_node	*other;
	int		rank;

	current = stack->top;
	while (current)
	{
		rank = 0;
		other = stack->top;
		while (other)
		{
			if (other->value < current->value)
				rank++;
			other = other->next;
		}
		current->index = rank;
		current = current->next;
	}
}

static int	add_split_numbers(t_stack *a, char **split)
{
	int	i;
	int	value;

	i = 0;
	if (!split[0])
		return (0);
	while (split[i])
	{
		if (!parse_number(split[i], &value))
			return (0);
		add_back(a, new_node(value));
		i++;
	}
	return (1);
}

static int	fill_stack(t_stack *a, int argc, char **argv)
{
	char	**split;
	int		i;
	int		valid;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		valid = add_split_numbers(a, split);
		free_split(split);
		if (!valid)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	if (!fill_stack(&a, argc, argv) || !check_duplicate(&a))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	assign_index(&a);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
