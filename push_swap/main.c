/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:08:02 by luli2             #+#    #+#             */
/*   Updated: 2026/08/03 11:12:39 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_number(const char *str, int *value)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	if (!str || *str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		number = number * 10 + (*str - '0');
		if (sign == 1 && number > INT_MAX)
			return (0);
		if (sign == -1 && -number < INT_MIN)
			return (0);
		str++;
	}
	*value = (int)(number * sign);
	return (1);
}

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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		value;

	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	i = 1;
	while (i < argc)
	{
		if (!parse_number(argv[i], &value))
		{
			write(2, "Error\n", 6);
			free_stack(&a);
			return (1);
		}
		add_back(&a, new_node(value));
		i++;
	}
	//test/print_stack("A", &a);
	if (!check_duplicate(&a))
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