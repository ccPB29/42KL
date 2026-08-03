/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 08:24:17 by luli2             #+#    #+#             */
/*   Updated: 2025-09-28 08:24:17 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = nb * ft_recursive_power(nb, power - 1);
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("2^0 = %d\n", ft_recursive_power(2, 0));
// 	printf("2^3 = %d\n", ft_recursive_power(2, 3));
// 	printf("5^4 = %d\n", ft_recursive_power(5, 4));
// 	printf("3^-2 = %d\n", ft_recursive_power(3, -2));
// 	return (0);
// }
