#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <unistd.h>

#define INT_MAX 2147483647
#define INT_MIN (-2147483648)

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_node	*new_node(int value);
void	add_back(t_stack *stack, t_node *new);

int		parse_number(const char *str, int *value);
int		check_duplicate(t_stack *stack);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* test */
#include <stdio.h>
void	print_stack(char *name, t_stack *stack);

#endif