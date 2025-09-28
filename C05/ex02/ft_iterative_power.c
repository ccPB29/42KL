/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 07:38:15 by luli2             #+#    #+#             */
/*   Updated: 2025-09-28 07:38:15 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = nb;
	while (power > 1)
	{
		i = i * nb;
		power--;
	}
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("2^0 = %d\n", ft_iterative_power(2, 0));
// 	printf("2^3 = %d\n", ft_iterative_power(2, 3));
// 	printf("5^4 = %d\n", ft_iterative_power(5, 4));
// 	printf("3^-2 = %d\n", ft_iterative_power(3, -2));
// 	return (0);
// }
