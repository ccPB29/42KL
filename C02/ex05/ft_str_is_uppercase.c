/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 07:04:58 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 07:04:58 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("Test1: %d\n", ft_str_is_uppercase("HELLO"));   // 全大写 → 1
// 	printf("Test2: %d\n", ft_str_is_uppercase("Hello"));   // 含小写 → 0
// 	printf("Test3: %d\n", ft_str_is_uppercase(""));        // 空字符串 → 1
// 	printf("Test4: %d\n", ft_str_is_uppercase("123ABC"));  // 含数字 → 0
// 	printf("Test5: %d\n", ft_str_is_uppercase("WORLD"));   // 全大写 → 1

// 	return 0;
// }
