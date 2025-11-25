/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:59:54 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:10:48 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>   // 用于对比系统 tolower
// #include "libft.h"   // 你的 ft_tolower

// int main(void)
// {
//     printf("=== Test ft_tolower ===\n\n");

//     int tests[] = {
//         // 大写字母（应该转换）
//         'A', 'B', 'Z',

//         // 小写字母（保持不变）
//         'a', 'z',

//         // 数字（保持不变）
//         '0', '9',

//         // 符号（保持不变）
//         '!', '~', ' ',

//         // 控制字符（保持不变）
//         '\n', '\t', 1, 31,

//         // ASCII 边界值
//         0, 127,

//         // 超出 ASCII（libft 只按 ASCII 处理）
//         -1, 200
//     };

//     int count = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < count; i++)
//     {
//         int c = tests[i];
//         int ft  = ft_tolower(c);
//         int sys = tolower(c);

//         if (c >= 32 && c <= 126)
//             printf("'%c' (%d): ft=%d('%c'), sys=%d('%c')\n",
//                     c, c, ft, ft, sys, sys);
//         else
//             printf("ascii %d: ft=%d, sys=%d\n", c, ft, sys);
//     }

//     return 0;
// }