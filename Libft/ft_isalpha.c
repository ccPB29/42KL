/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:06:07 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:12:35 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
//     printf("=== Test ft_isalpha ===\n\n");

//     char tests[] = {
//         'A', 'Z',      // 大写字母
//         'a', 'z',      // 小写字母
//         '0', '9',      // 数字（应返回 0）
//         '@', '[',      // 特殊字符
//         '\n',          // 控制字符
//         -1, 127        // 边界情况（可能被测试）
//     };

//     int num_tests = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < num_tests; i++)
//     {
//         char c = tests[i];
//         int result = ft_isalpha(c);

//         if (c >= 32 && c <= 126)
//             printf("'%c' (ascii %d): %d\n", c, c, result);
//         else
//             printf("ascii %d (non-printable): %d\n", c, result);
//     }

//     return 0;
// }