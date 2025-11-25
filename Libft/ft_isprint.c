/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:34:09 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:12:25 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
//     printf("=== Test ft_isprint ===\n\n");

//     int tests[] = {
//         // 可打印范围：32 ~ 126
//         ' ', 'A', 'z', '0', '~',

//         // 不可打印范围
//         0, 1, 7, 31,   // 控制字符
//         127,           // DEL

//         // 超出 ASCII
//         -1, -10, 128, 255
//     };

//     int count = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < count; i++)
//     {
//         int c = tests[i];
//         int result = ft_isprint(c);

//         if (c >= 32 && c <= 126)
//             printf("'%c' (ascii %d): %d\n", c, c, result);
//         else
//             printf("ascii %d: %d\n", c, result);
//     }

//     return 0;
// }