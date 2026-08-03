/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 06:49:08 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 06:49:08 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("Test1: %d\n", ft_str_is_alpha("Hello"));     // 全是字母 → 1
// 	printf("Test2: %d\n", ft_str_is_alpha("Hello123")); // 有数字 → 0
// 	printf("Test3: %d\n", ft_str_is_alpha("HELLO"));    // 全大写字母 → 1
// 	printf("Test4: %d\n", ft_str_is_alpha(""));         // 空字符串 → 1
// 	printf("Test5: %d\n", ft_str_is_alpha("Hi!"));      // 有符号 → 0

// 	return 0;
// }