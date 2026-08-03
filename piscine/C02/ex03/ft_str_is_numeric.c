/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 06:59:42 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 06:59:42 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("Test1: %d\n", ft_str_is_numeric("12345"));   // 全是数字 → 1
// 	printf("Test2: %d\n", ft_str_is_numeric("42a"));     // 有字母 → 0
// 	printf("Test3: %d\n", ft_str_is_numeric(""));        // 空字符串 → 1
// 	printf("Test4: %d\n", ft_str_is_numeric("007"));     // 还是数字 → 1
// 	printf("Test5: %d\n", ft_str_is_numeric("12 34"));   // 含空格 → 0

// 	return 0;
// }