/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:35:46 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 16:37:45 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void    ft_striteri(char *s, void (*f)(unsigned int, char*));

// void    test_func(unsigned int i, char *c)
// {
//     if (i % 2 == 0)
//     {
//         if (*c >= 'a' && *c <= 'z')
//             *c = *c - 32; // 假装变大写
//     }
//     else
//     {
//         if (*c >= 'A' && *c <= 'Z')
//             *c = *c + 32; // 假装变小写
//     }
// }

// int main(void)
// {
//     char str[] = "Hello World!";

//     printf("Original : %s\n", str);
//     ft_striteri(str, test_func);
//     printf("Modified : %s\n", str);

//     return 0;
// }