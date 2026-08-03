/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 06:53:38 by luli2             #+#    #+#             */
/*   Updated: 2025-09-28 06:53:38 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 1;
	while (nb > 0)
	{
		i = i * nb;
		nb--;
	}
	return (i);
}

// #include <stdio.h>

// int main(void)
// {
// 	int i;

// 	for (i = -1; i <= 10; i++)
// 	{
// 		printf("%d! = %d\n", i, ft_iterative_factorial(i));
// 	}
// 	return (0);
// }
