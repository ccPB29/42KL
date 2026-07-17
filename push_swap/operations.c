/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:42:32 by luli2             #+#    #+#             */
/*   Updated: 2026/07/17 22:22:35 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!b || b->size == 0)
		return ;
	temp = b->top;
	b->top = b->top->next;
	temp->next = a->top;
	a->top = temp;
	b->size--;
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!a || a->size == 0)
		return ;
	temp = a->top;
	a->top = a->top->next;
	temp->next = b->top;
	b->top = temp;
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}

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

static void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*prev;

	if (!stack || stack->size < 2)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
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