/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 08:45:53 by luli2             #+#    #+#             */
/*   Updated: 2025-09-28 08:45:53 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= (nb / i))
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("sqrt(16) = %d\n", ft_sqrt(16));
// 	printf("sqrt(25) = %d\n", ft_sqrt(25));
// 	printf("sqrt(10) = %d\n", ft_sqrt(10));
// 	printf("sqrt(-4) = %d\n", ft_sqrt(-4));
// 	printf("sqrt(0) = %d\n", ft_sqrt(0));
// 	return (0);
// }
