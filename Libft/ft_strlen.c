/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:35:44 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:44:38 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
//     printf("=== Test ft_strlen ===\n\n");

//     const char *tests[] = {
//         "",                         // 空字符串
//         "a",                        // 单字符
//         "Hello",                    // 普通字符串
//         "42 KL!",                   // 含空格
//         "你好",                     // UTF-8 多字节字符（长度应该按字节算）
//         "Line1\nLine2",             // 含换行符，但不是终止符
//         "\0abc",                    // 第一个就是 '\0'，长度 = 0
//         "abc\0def",                 // 中间 '\0'，结果 = 3
//     };

//     int count = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < count; i++)
//     {
//         const char *s = tests[i];
//         size_t len = ft_strlen(s);

//         // 只在可打印时打印内容，否则只打地址
//         if (s[0] >= 32 && s[0] <= 126)
//             printf("Input: \"%s\" → ft_strlen = %zu\n", s, len);
//         else
//  printf("Input starts with non-printable → ft_strlen = %zu\n", len);
//     }

//     return 0;
// }