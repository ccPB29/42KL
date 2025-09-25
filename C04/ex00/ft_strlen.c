/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 10:02:16 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 10:02:16 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("len of \"\" = %d\n", ft_strlen(""));            // 空字符串
// 	printf("len of \"hello\" = %d\n", ft_strlen("hello"));  // 普通字符串
// 	printf("len of \"42 KL\" = %d\n", ft_strlen("42 KL"));  // 含空格
// 	printf("len of \"longstring\" = %d\n", ft_strlen("longstring")); // 长点的
// 	return (0);
// }
