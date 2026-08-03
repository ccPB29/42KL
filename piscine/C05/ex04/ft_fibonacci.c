/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 08:32:58 by luli2             #+#    #+#             */
/*   Updated: 2025-09-28 08:32:58 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("F(%d) = %d\n", i, ft_fibonacci(i));
// 		i++;
// 	}
// 	return (0);
// }
