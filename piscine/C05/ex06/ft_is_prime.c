/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 09:25:00 by luli2             #+#    #+#             */
/*   Updated: 2025-09-28 09:25:00 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	i = 2;
	while (i <= (nb / i))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("1 -> %d\n", ft_is_prime(1));
// 	printf("2 -> %d\n", ft_is_prime(2));
// 	printf("17 -> %d\n", ft_is_prime(17));
// 	printf("18 -> %d\n", ft_is_prime(18));
// 	printf("97 -> %d\n", ft_is_prime(97));
// 	printf("100 -> %d\n", ft_is_prime(100));
// 	return (0);
// }
