/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:18:13 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:05:09 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
//     printf("=== Test ft_isdigit ===\n\n");

//     int tests[] = {
//         '0', '1', '5', '9',   // 数字字符
//         'A', 'z',             // 字母
//         '/', ':',             // 紧邻数字区间的符号（ASCII 47, 58）
//         ' ',                  // 空格
//         '\n',                 // 控制字符
//         -1, 127               // 边界值
//     };

//     int num_tests = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < num_tests; i++)
//     {
//         int c = tests[i];
//         int result = ft_isdigit(c);

//         if (c >= 32 && c <= 126)
//             printf("'%c' (ascii %d): %d\n", c, c, result);
//         else
//             printf("ascii %d (non-printable): %d\n", c, result);
//     }

//     return 0;
// }