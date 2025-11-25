/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:58:08 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:10:42 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>   // 用于对比系统 toupper
// #include "libft.h"   // 你的 ft_toupper

// int main(void)
// {
//     printf("=== Test ft_toupper ===\n\n");

//     int tests[] = {
//         // 小写字母（应该变成大写）
//         'a', 'b', 'z',

//         // 大写字母（应保持不变）
//         'A', 'Z',

//         // 非字母字符（应保持不变）
//         '0', '9', '!', '~', ' ',

//         // 控制字符（保持不变）
//         '\n', '\t', 1, 31,

//         // 边界值（ASCII）
//         0, 127,

//         // 超出 ASCII（libft 应只按 ASCII 范围处理）
//         -1, 200
//     };

//     int count = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < count; i++)
//     {
//         int c = tests[i];
//         int ft  = ft_toupper(c);
//         int sys = toupper(c);

//         // 可打印字符输出内容，不可打印输出数字
//         if (c >= 32 && c <= 126)
//             printf("'%c' (%d): ft=%d('%c'), sys=%d('%c')\n",
//                     c, c, ft, ft, sys, sys);
//         else
//             printf("ascii %d: ft=%d, sys=%d\n", c, ft, sys);
//     }

//     return 0;
// }