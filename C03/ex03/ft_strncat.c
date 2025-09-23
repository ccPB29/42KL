/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:53:21 by luli2             #+#    #+#             */
/*   Updated: 2025-09-23 10:53:21 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < nb && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char buf1[50] = "Hello";
// 	char buf2[50] = "Hello";

// 	printf("dest 原始: \"%s\"\n", buf1);

// 	// 测试1：nb 大于 src 长度
// 	ft_strncat(buf1, " World", 10);
// 	strncat(buf2, " World", 10);
// 	printf("ft_strncat: \"%s\"\n", buf1);
// 	printf("strncat   : \"%s\"\n\n", buf2);

// 	// 测试2：nb 小于 src 长度
// 	char buf3[50] = "Hello";
// 	char buf4[50] = "Hello";
// 	ft_strncat(buf3, "ABCDEFG", 3);
// 	strncat(buf4, "ABCDEFG", 3);
// 	printf("ft_strncat: \"%s\"\n", buf3);
// 	printf("strncat   : \"%s\"\n\n", buf4);

// 	// 测试3：nb 正好等于 src 长度
// 	char buf5[50] = "X";
// 	char buf6[50] = "X";
// 	ft_strncat(buf5, "12345", 5);
// 	strncat(buf6, "12345", 5);
// 	printf("ft_strncat: \"%s\"\n", buf5);
// 	printf("strncat   : \"%s\"\n", buf6);

// 	return 0;
// }