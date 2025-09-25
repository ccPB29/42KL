/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 10:49:13 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 10:49:13 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	i;
	char	c;

	i = nb;
	if (i < 0)
	{
		write(1, "-", 1);
		i = -1 * i;
	}
	if (i < 10)
	{
		c = '0' + i;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}

// int	main(void)
// {
// 	ft_putnbr(0);
// 	write(1, "\n", 1);
// 	ft_putnbr(42);
// 	write(1, "\n", 1);
// 	ft_putnbr(-42);
// 	write(1, "\n", 1);
// 	ft_putnbr(2147483647);   // INT_MAX
// 	write(1, "\n", 1);
// 	ft_putnbr(-2147483648);  // INT_MIN
// 	write(1, "\n", 1);

// 	return (0);
// }
