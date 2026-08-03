/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 07:02:54 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 07:02:54 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("Test1: %d\n", ft_str_is_lowercase("hello"));   // 全小写 → 1
// 	printf("Test2: %d\n", ft_str_is_lowercase("Hello"));   // 有大写 → 0
// 	printf("Test3: %d\n", ft_str_is_lowercase(""));        // 空字符串 → 1
// 	printf("Test4: %d\n", ft_str_is_lowercase("abc123"));  // 含数字 → 0
// 	printf("Test5: %d\n", ft_str_is_lowercase("world"));   // 全小写 → 1

// 	return 0;
// }