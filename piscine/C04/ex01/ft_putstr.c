/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 10:45:44 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 10:45:44 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	ft_putstr("Hello, world!\n");   // 普通字符串
// 	ft_putstr("");                  // 空字符串（啥都不会输出）
// 	// ft_putstr(NULL);             // 小心！NULL 会段错误

// 	return (0);
// }
