/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:34:57 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:43:40 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		remaining;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		b = big;
		l = little;
		remaining = len;
		while (*l != '\0' && remaining > 0 && *b == *l)
		{
			b++;
			l++;
			remaining--;
		}
		if (*l == '\0')
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>     // 系统 strnstr (BSD)
// #include "libft.h"      // 你的 ft_strnstr

// static void print_case(
//     const char *label,
//     const char *big, const char *little, size_t len,
//     char *ft_res, char *sys_res)
// {
//     printf("%s\n", label);
//     printf("  big    : \"%s\"\n", big);
//     printf("  little : \"%s\"\n", little);
//     printf("  len    : %zu\n", len);

//     printf("  ft_strnstr : %s\n",
//            ft_res ? ft_res : "NULL");
//     printf("  strnstr    : %s\n",
//            sys_res ? sys_res : "NULL");

//     int match = (ft_res == sys_res ||
//                 (ft_res && sys_res && strcmp(ft_res, sys_res) == 0));

//     printf("  Match? %s\n\n", match ? "YES" : "NO");
// }

// int main(void)
// {
//     printf("=== Test ft_strnstr ===\n\n");

//     // Test 1: Basic match
//     {
//         const char *big = "Hello World!";
//         const char *little = "World";
//         size_t len = 20;
//         print_case("Test 1: Basic match",
//                    big, little, len,
//                    ft_strnstr(big, little, len),
//                    strnstr(big, little, len));
//     }

//     // Test 2: No match
//     {
//         const char *big = "Hello World!";
//         const char *little = "42";
//         print_case("Test 2: No match",
//                    big, little, 20,
//                    ft_strnstr(big, little, 20),
//                    strnstr(big, little, 20));
//     }

//     // Test 3: little = "" (must return big)
//     {
//         print_case("Test 3: little = \"\"",
//                    "Hello", "", 5,
//                    ft_strnstr("Hello", "", 5),
//                    strnstr("Hello", "", 5));
//     }

//     // Test 4: len too small (match exists but past len)
//     {
//         const char *big = "Hello World!";
//         const char *little = "World";
//         size_t len = 7;  // "World" starts at index 6, but can't fit fully
//         print_case("Test 4: match exists but len too small",
//                    big, little, len,
//                    ft_strnstr(big, little, len),
//                    strnstr(big, little, len));
//     }

//     // Test 5: len cuts through potential match
//     {
//         const char *big = "12345ABCDE";
//         const char *little = "ABCDE";
//         size_t len = 8;  // 8 字节以内无法完整包含 "ABCDE"
//         print_case("Test 5: len cuts partial match",
//                    big, little, len,
//                    ft_strnstr(big, little, len),
//                    strnstr(big, little, len));
//     }

//     // Test 6: Match at position 0
//     {
//         print_case("Test 6: match at start",
//                    "ABCDE", "ABC", 5,
//                    ft_strnstr("ABCDE", "ABC", 5),
//                    strnstr("ABCDE", "ABC", 5));
//     }

//     // Test 7: big contains long prefix, match near end but within len
//     {
//         const char *big = "HelloHelloWorld";
//         const char *little = "World";
//         size_t len = 20;
//         print_case("Test 7: match near end, valid",
//                    big, little, len,
//                    ft_strnstr(big, little, len),
//                    strnstr(big, little, len));
//     }

//     // Test 8: n = 0
//     {
//         print_case("Test 8: len = 0",
//                    "Hello", "He", 0,
//                    ft_strnstr("Hello", "He", 0),
//                    strnstr("Hello", "He", 0));
//     }

//     // Test 9: Embedded null in little
// (undefined in real life but good check)
//     {
//         char big[] = "ABC\0DEF";
//         char little[] = "C\0D"; // strnstr 按字节比较✔
//         print_case("Test 9: embedded nulls",
//                    big, little, 6,
//                    ft_strnstr(big, little, 6),
//                    strnstr(big, little, 6));
//     }

//     return 0;
// }