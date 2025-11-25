/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:07:31 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:43:11 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last);
}

// #include <stdio.h>
// #include <string.h>     // 系统 strrchr
// #include "libft.h"      // 你的 ft_strrchr

// static void print_res(const char *label, char *ft_res, char *sys_res)
// {
//     printf("%s\n", label);

//     if (ft_res)
//         printf("  ft_strrchr : \"%s\"\n", ft_res);
//     else
//         printf("  ft_strrchr : NULL\n");

//     if (sys_res)
//         printf("  strrchr    : \"%s\"\n", sys_res);
//     else
//         printf("  strrchr    : NULL\n");

//     printf("  Match? %s\n\n",
//            (ft_res == sys_res ||
//            (ft_res && sys_res && strcmp(ft_res, sys_res) == 0))
//            ? "YES" : "NO");
// }

// int main(void)
// {
//     printf("=== Test ft_strrchr ===\n\n");

//     const char *s = "Hello World!";

//     // Test 1: Normal char
//     print_res("Test 1: find 'o'",
//               ft_strrchr(s, 'o'),
//               strrchr(s, 'o'));

//     // Test 2: character not present
//     print_res("Test 2: find 'x' (not present)",
//               ft_strrchr(s, 'x'),
//               strrchr(s, 'x'));

//     // Test 3: find first character (only once)
//     print_res("Test 3: find 'H'",
//               ft_strrchr(s, 'H'),
//               strrchr(s, 'H'));

//     // Test 4: find last character
//     print_res("Test 4: find '!'",
//               ft_strrchr(s, '!'),
//               strrchr(s, '!'));

//     // Test 5: repeated characters — must return LAST occurrence
//     print_res("Test 5: repeated char 'l'",
//               ft_strrchr(s, 'l'),
//               strrchr(s, 'l'));

//     // Test 6: c == '\0' — 返回指向字符串末尾 '\0'
//     print_res("Test 6: find '\\0'",
//               ft_strrchr(s, '\0'),
//               strrchr(s, '\0'));

//     // Test 7: signed/unsigned char edge case
//     char weird[] = "ABCD\xff""EFG";
//     print_res("Test 7: find 255",
//               ft_strrchr(weird, 255),
//               strrchr(weird, 255));

//     return 0;
// }