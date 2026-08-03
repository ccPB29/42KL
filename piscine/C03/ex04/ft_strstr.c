/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 11:26:29 by luli2             #+#    #+#             */
/*   Updated: 2025-09-23 11:26:29 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		a;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		a = i;
		while (str[i] == to_find[j] && to_find[j] != '\0')
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
			return (&str[a]);
		i = a + 1;
		j = 0;
	}
	return (NULL);
}

// #include <stdio.h>

// int main(void)
// {
// 	char s[] = "Hello World";

// 	// 1. 匹配开头
// 	printf("Find \"Hello\" in \"%s\": %s\n", s, ft_strstr(s, "Hello"));

// 	// 2. 匹配中间
// 	printf("Find \"World\" in \"%s\": %s\n", s, ft_strstr(s, "World"));

// 	// 3. 匹配子串
// 	printf("Find \"lo\" in \"%s\": %s\n", s, ft_strstr(s, "lo"));

// 	// 4. 找不到
// 	printf("Find \"42\" in \"%s\": %s\n", s, ft_strstr(s, "42"));

// 	// 5. needle 是空串
// 	printf("Find \"\" in \"%s\": %s\n", s, ft_strstr(s, ""));

// 	return 0;
// }
