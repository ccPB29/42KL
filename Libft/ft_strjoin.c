/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:58:06 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 15:01:13 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
//     char *s;

//     s = ft_strjoin("Hello", "World");
//     printf("%s\n", s);
//     free(s);

//     s = ft_strjoin("", "42");
//     printf("%s\n", s);
//     free(s);

//     s = ft_strjoin("Test", "");
//     printf("%s\n", s);
//     free(s);

//     return 0;
// }