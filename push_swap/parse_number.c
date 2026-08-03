/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:08:02 by luli2             #+#    #+#             */
/*   Updated: 2026/08/03 13:05:29 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	build_number(const char *str, int sign, long *number)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		*number = *number * 10 + (*str - '0');
		if (sign == 1 && *number > INT_MAX)
			return (0);
		if (sign == -1 && -(*number) < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}

int	parse_number(const char *str, int *value)
{
	long	number;
	int		sign;

	if (!str || *str == '\0')
		return (0);
	number = 0;
	sign = get_sign(&str);
	if (*str == '\0' || !build_number(str, sign, &number))
		return (0);
	*value = (int)(number * sign);
	return (1);
}
