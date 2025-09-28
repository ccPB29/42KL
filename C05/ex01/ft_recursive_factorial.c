/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 07:21:07 by luli2             #+#    #+#             */
/*   Updated: 2025-09-28 07:21:07 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	i = nb * ft_recursive_factorial(nb - 1);
	return (i);
}

// #include <stdio.h>

// int main(void)
// {
// 	int n = 5;

// 	printf("%d! = %d\n", n, ft_recursive_factorial(n));
// 	return (0);
// }
