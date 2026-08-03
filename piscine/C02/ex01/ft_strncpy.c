/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 06:31:02 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 06:31:02 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// #include <stdio.h>

// int main(void)
// {
// 	char src1[] = "Hi";
// 	char dest1[10];
// 	char dest2[10];

// 	// case1: src 长度小于 n
// 	ft_strncpy(dest1, src1, 5);
// 	printf("Case1: \"%s\"\n", dest1);

// 	// case2: src 长度等于 n
// 	char src2[] = "Hello";
// 	ft_strncpy(dest2, src2, 5);
// 	printf("Case2: \"%s\"\n", dest2);

// 	// case3: src 长度大于 n
// 	char src3[] = "HelloWorld";
// 	char dest3[20];
// 	ft_strncpy(dest3, src3, 3);
// 	printf("Case3: \"%s\"\n", dest3);

// 	return 0;
// }