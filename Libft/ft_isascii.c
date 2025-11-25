/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:26:36 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:12:32 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
//     printf("=== Test ft_isascii ===\n\n");

//     int tests[] = {
//         // 正常 ASCII 范围
//         0, 1, 31, 32, 65, 97, 126, 127,

//         // 超出 ASCII 范围
//         -1, -5, 128, 255, 300
//     };

//     int count = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < count; i++)
//     {
//         int c = tests[i];
//         int result = ft_isascii(c);

//         if (c >= 32 && c <= 126)
//             printf("'%c' (ascii %d): %d\n", c, c, result);
//         else
//             printf("ascii %d: %d\n", c, result);
//     }

//     return 0;
// }