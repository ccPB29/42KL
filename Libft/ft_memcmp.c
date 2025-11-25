/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:19:35 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:39:56 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// static void print_case(const char *label,
//                        const void *s1, const void *s2, size_t n,
//                        int r_ft, int r_sys)
// {
//     printf("%s\n", label);
//     printf("  n    : %zu\n", n);
//     printf("  ft   : %d\n", r_ft);
//     printf("  sys  : %d\n", r_sys);

//     // memcmp 只要求返回值的正负一致，不需要数值完全一样
//     int match = ((r_ft < 0 && r_sys < 0) ||
//                  (r_ft > 0 && r_sys > 0) ||
//                   r_ft == r_sys);

//     printf("  Match? %s\n\n", match ? "YES" : "NO");
// }

// int main(void)
// {
//     printf("=== Test ft_memcmp ===\n\n");

//     // Test 1: equal memory blocks
//     {
//         char a[] = "Hello";
//         char b[] = "Hello";
//         print_case("Test 1: equal",
//                    a, b, 5,
//                    ft_memcmp(a, b, 5),
//                    memcmp(a, b, 5));
//     }

//     // Test 2: difference at first byte
//     {
//         char a[] = "Zello";
//         char b[] = "Hello";
//         print_case("Test 2: first byte differs",
//                    a, b, 5,
//                    ft_memcmp(a, b, 5),
//                    memcmp(a, b, 5));
//     }

//     // Test 3: difference inside block
//     {
//         char a[] = "HeLlo";
//         char b[] = "Hello";
//         print_case("Test 3: middle differs",
//                    a, b, 5,
//                    ft_memcmp(a, b, 5),
//                    memcmp(a, b, 5));
//     }

//     // Test 4: n smaller than difference location
//     {
//         char a[] = "HeLlo";
//         char b[] = "Hello";
//         print_case("Test 4: no diff within n",
//                    a, b, 2,   // 前两字节相同
//                    ft_memcmp(a, b, 2),
//                    memcmp(a, b, 2));
//     }

//     // Test 5: binary data
//     {
//         unsigned char a[] = {1,2,3,4,5};
//         unsigned char b[] = {1,2,9,4,5};
//         print_case("Test 5: binary diff",
//                    a, b, 5,
//                    ft_memcmp(a, b, 5),
//                    memcmp(a, b, 5));
//     }

//     // Test 6: embedded null bytes
//     {
//         char a[] = {'A','B','\0','C'};
//         char b[] = {'A','B','\0','D'};
//         print_case("Test 6: embedded null",
//                    a, b, 4,
//                    ft_memcmp(a, b, 4),
//                    memcmp(a, b, 4));
//     }

//     // Test 7: unsigned char correctness (0xFF)
//     {
//         unsigned char a[] = {0x01, 0xFF, 0x10};
//         unsigned char b[] = {0x01, 0x00, 0x10};
//         print_case("Test 7: unsigned char 0xFF",
//                    a, b, 3,
//                    ft_memcmp(a, b, 3),
//                    memcmp(a, b, 3));
//     }

//     // Test 8: n = 0
//     {
//         char a[] = "ABC";
//         char b[] = "XYZ";
//         print_case("Test 8: n = 0",
//                    a, b, 0,
//                    ft_memcmp(a, b, 0),
//                    memcmp(a, b, 0));
//     }

//     return 0;
// }