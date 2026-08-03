/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations copy 3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:42:32 by luli2             #+#    #+#             */
/*   Updated: 2026/08/03 12:57:03 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

// int	main(void)
// {
// 	t_stack	a;
// 	t_stack	b;

// 	a.top = NULL;
// 	a.size = 0;
// 	b.top = NULL;
// 	b.size = 0;

// 	add_back(&a, new_node(3));
// 	add_back(&a, new_node(2));
// 	add_back(&a, new_node(1));

// 	add_back(&b, new_node(6));
// 	add_back(&b, new_node(5));
// 	add_back(&b, new_node(4));

// 	printf("===== 初始 =====\n");
// 	print_stack("A", &a);
// 	print_stack("B", &b);

// 	sa(&a);
// 	printf("===== sa =====\n");
// 	print_stack("A", &a);

// 	sb(&b);
// 	printf("===== sb =====\n");
// 	print_stack("B", &b);

// 	ss(&a, &b);
// 	printf("===== ss =====\n");
// 	print_stack("A", &a);
// 	print_stack("B", &b);

// 	pa(&a, &b);
// 	printf("===== pa =====\n");
// 	print_stack("A", &a);
// 	print_stack("B", &b);

// 	pb(&a, &b);
// 	printf("===== pb =====\n");
// 	print_stack("A", &a);
// 	print_stack("B", &b);

// 	ra(&a);
// 	printf("===== ra =====\n");
// 	print_stack("A", &a);

// 	rb(&b);
// 	printf("===== rb =====\n");
// 	print_stack("B", &b);

// 	rr(&a, &b);
// 	printf("===== rr =====\n");
// 	print_stack("A", &a);
// 	print_stack("B", &b);

// 	rra(&a);
// 	printf("===== rra =====\n");
// 	print_stack("A", &a);

// 	rrb(&b);
// 	printf("===== rrb =====\n");
// 	print_stack("B", &b);

// 	rrr(&a, &b);
// 	printf("===== rrr =====\n");
// 	print_stack("A", &a);
// 	print_stack("B", &b);

// 	return (0);
// }