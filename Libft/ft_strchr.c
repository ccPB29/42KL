/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:01:28 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:32:50 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>     // 用于对比系统 strchr
// #include "libft.h"      // 你的 ft_strchr

// // 安全打印指针结果
// static void print_result(const char *label, char *ft_res, char *sys_res)
// {
//     printf("%s\n", label);

//     if (ft_res)
//         printf("  ft_strchr  : \"%s\"\n", ft_res);
//     else
//         printf("  ft_strchr  : NULL\n");

//     if (sys_res)
//         printf("  strchr     : \"%s\"\n", sys_res);
//     else
//         printf("  strchr     : NULL\n");

//     printf("  Match? %s\n\n", (ft_res == sys_res ||
//            (ft_res && sys_res && strcmp(ft_res, sys_res) == 0)) ?
//            "YES" : "NO");
// }

// int main(void)
// {
//     printf("=== Test ft_strchr ===\n\n");

//     const char *s = "Hello World!";

//     // Test 1: normal char in string
//     print_result(
//         "Test 1: find 'o'",
//         ft_strchr(s, 'o'),
//         strchr(s, 'o')
//     );

//     // Test 2: char not in string
//     print_result(
//         "Test 2: find 'x' (not present)",
//         ft_strchr(s, 'x'),
//         strchr(s, 'x')
//     );

//     // Test 3: find first character
//     print_result(
//         "Test 3: find 'H'",
//         ft_strchr(s, 'H'),
//         strchr(s, 'H')
//     );

//     // Test 4: find last character
//     print_result(
//         "Test 4: find '!'",
//         ft_strchr(s, '!'),
//         strchr(s, '!')
//     );

//     // Test 5: c == '\0'（重要！必须返回指向终止符的位置）
//     print_result(
//         "Test 5: find '\\0'",
//         ft_strchr(s, '\0'),
//         strchr(s, '\0')
//     );

//     // Test 6: repeated characters — must return FIRST occurrence
//     print_result(
//         "Test 6: find 'l' (repeated)",
//         ft_strchr(s, 'l'),
//         strchr(s, 'l')
//     );

//     // Test 7: signed/unsigned char issue
//     // 字符 255 → 在 char 是 signed 的平台上会变成 -1
//     char weird[] = "ABC\xff""DEF";  // 添加 255
//     print_result(
//         "Test 7: find char 255",
//         ft_strchr(weird, 255),
//         strchr(weird, 255)
//     );

//     return 0;
// }