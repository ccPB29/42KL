/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:47:55 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 16:12:01 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>
// #include <ctype.h>

// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// char	test_func(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return (toupper(c));
// 	return (tolower(c));
// }

// int main(void)
// {
//     char *result;

//     result = ft_strmapi("Hello World!", test_func);
//     if (!result)
//     {
//         printf("malloc failed\n");
//         return (1);
//     }
//     printf("Original : %s\n", "Hello World!");
//     printf("Mapped   : %s\n", result);
//     free(result);
//     return (0);
// }
