/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:25:19 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:50:17 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'));
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
//     printf("=== Test ft_isalnum ===\n\n");

//     int tests[] = {
//         // 数字
//         '0', '5', '9',

//         // 大写字母
//         'A', 'Z',

//         // 小写字母
//         'a', 'z',

//         // 字母与数字区间外的字符
//         '/', ':',      //符号
//         '@', '[',      //接近字母区间的字符
//         '`', '{',

//         // 控制字符
//         '\n', ' ',

//         // 边界（负数 & 127）
//         -1, 127
//     };

//     int count = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < count; i++)
//     {
//         int c = tests[i];
//         int result = ft_isalnum(c);

//         if (c >= 32 && c <= 126)
//             printf("'%c' (ascii %d): %d\n", c, c, result);
//         else
//             printf("ascii %d (non-printable): %d\n", c, result);
//     }

//     return 0;
// }