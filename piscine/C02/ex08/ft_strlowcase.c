/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 07:24:43 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 07:24:43 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str1[] = "HELLO WORLD!";
// 	char str2[] = "AlreadyLower";
// 	char str3[] = "1234ABCdef";
// 	char str4[] = "";

// 	printf("Before: %s\n", str1);
// 	printf("After : %s\n\n", ft_strlowcase(str1));

// 	printf("Before: %s\n", str2);
// 	printf("After : %s\n\n", ft_strlowcase(str2));

// 	printf("Before: %s\n", str3);
// 	printf("After : %s\n\n", ft_strlowcase(str3));

// 	printf("Before: \"%s\"\n", str4);
// 	printf("After : \"%s\"\n", ft_strlowcase(str4));

// 	return (0);
// }
