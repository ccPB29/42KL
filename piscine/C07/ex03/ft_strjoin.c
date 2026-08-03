/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 09:25:50 by luli2             #+#    #+#             */
/*   Updated: 2025-10-01 09:25:50 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*cat(char *str, char *c)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		i++;
	}
	j = 0;
	while (c[j])
	{
		str[i + j] = c[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*c;
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (i < size)
		l = l + len(strs[i++]);
	l = l + (size - 1) * len(sep) + 1;
	c = (char *)malloc(l * sizeof(char));
	if (!c)
		return (NULL);
	c[0] = '\0';
	if (size <= 0)
		return (c);
	i = 0;
	while (i < size)
	{
		cat(c, strs[i]);
		if (i < size - 1)
			cat(c, sep);
		i++;
	}
	return (c);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	len(char *str);
// char	*cat(char *str, char *c);
// char	*ft_strjoin(int size, char **strs, char *sep);

// int main(void)
// {
//     char *arr[] = {"abc", "123", "xyz"};
//     char *sep = "-";
//     char *result;

//     result = ft_strjoin(3, arr, sep);
//     if (result)
//     {
//         printf("拼接结果: %s\n", result);
//         free(result);
//     }

//     // 测试 size = 0
//     result = ft_strjoin(0, arr, sep);
//     if (result)
//     {
//         printf("size=0 的结果: \"%s\"\n", result);
//         free(result);
//     }

//     return 0;
// }
