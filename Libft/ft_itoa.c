/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:41:57 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 15:47:15 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = (long)n;
	len = count_len(nb);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (len-- > 0 && str[len] != '-')
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

// #include <stdio.h>
// #include <limits.h>

// char    *ft_itoa(int n);

// int main(void)
// {
//     int tests[] = {0, 42, -42, 123456, -123456,
//                    INT_MAX, INT_MIN};
//     int size = sizeof(tests) / sizeof(tests[0]);
//     int i = 0;
//     char *str;

//     while (i < size)
//     {
//         str = ft_itoa(tests[i]);
//         if (!str)
//         {
//             printf("malloc failed for %d\n", tests[i]);
//             return (1);
//         }
//         printf("ft_itoa(%d) = %s\n", tests[i], str);
//         free(str);
//         i++;
//     }
//     return (0);
// }
