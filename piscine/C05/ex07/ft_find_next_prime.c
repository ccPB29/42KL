/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 09:37:44 by luli2             #+#    #+#             */
/*   Updated: 2025-09-28 09:37:44 by luli2            ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("Next prime after 1  = %d\n", ft_find_next_prime(1));
// 	printf("Next prime after 2  = %d\n", ft_find_next_prime(2));
// 	printf("Next prime after 14 = %d\n", ft_find_next_prime(14));
// 	printf("Next prime after 17 = %d\n", ft_find_next_prime(17));
// 	printf("Next prime after 20 = %d\n", ft_find_next_prime(20));
// 	printf("Next prime after 97 = %d\n", ft_find_next_prime(97));
// 	printf("Next prime after 100 = %d\n", ft_find_next_prime(100));
// 	return (0);
// }
