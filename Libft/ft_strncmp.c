/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:09:52 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:32:02 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			return (0);
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// static void print_case(const char *label,
//                        const char *s1, const char *s2, size_t n,
//                        int r_ft, int r_sys)
// {
//     printf("%s\n", label);
//     printf("  s1   : \"%s\"\n", s1);
//     printf("  s2   : \"%s\"\n", s2);
//     printf("  n    : %zu\n", n);
//     printf("  ft   : %d\n", r_ft);
//     printf("  sys  : %d\n", r_sys);
//     printf("  Match? %s\n\n", 
//		((r_ft < 0 && r_sys < 0) || (r_ft > 0 && r_sys > 0) || r_ft == r_sys)
//            ? "YES" : "NO");
// }

// int main(void)
// {
//     printf("=== Test ft_strncmp ===\n\n");

//     // Test 1: equal strings
//     {
//         const char *a = "Hello";
//         const char *b = "Hello";
//         print_case("Test 1: equal",
//                    a, b, 10,
//                    ft_strncmp(a, b, 10),
//                    strncmp(a, b, 10));
//     }

//     // Test 2: differ at position
//     {
//         const char *a = "Hello";
//         const char *b = "Hemlo";
//         print_case("Test 2: differ 1",
//                    a, b, 3,
//                    ft_strncmp(a, b, 3),
//                    strncmp(a, b, 3));
//     }

//     // Test 3: differ later, but n too small
//     {
//         const char *a = "Hello";
//         const char *b = "Hellz";
//         print_case("Test 3: differ but n=4",
//                    a, b, 4,
//                    ft_strncmp(a, b, 4),
//                    strncmp(a, b, 4));
//     }

//     // Test 4: n = 0
//     {
//         const char *a = "ABC";
//         const char *b = "XYZ";
//         print_case("Test 4: n = 0",
//                    a, b, 0,
//                    ft_strncmp(a, b, 0),
//                    strncmp(a, b, 0));
//     }

//     // Test 5: s1 shorter (stop at null)
//     {
//         const char *a = "Hi";
//         const char *b = "Hizzzz";
//         print_case("Test 5: s1 ends first",
//                    a, b, 10,
//                    ft_strncmp(a, b, 10),
//                    strncmp(a, b, 10));
//     }

//     // Test 6: s2 shorter
//     {
//         const char *a = "Hizzzz";
//         const char *b = "Hi";
//         print_case("Test 6: s2 ends first",
//                    a, b, 10,
//                    ft_strncmp(a, b, 10),
//                    strncmp(a, b, 10));
//     }

//     // Test 7: compare with NULL inside (embedded '\0')
//     {
//         const char a[] = {'A','B','\0','C'};
//         const char b[] = {'A','B','\0','D'};
//         print_case("Test 7: embedded null",
//                    a, b, 4,
//                    ft_strncmp(a, b, 4),
//                    strncmp(a, b, 4));
//     }

//     // Test 8: unsigned char test
//     {
//         char a[] = "A\xff";
//         char b[] = "A\x01";
//         print_case("Test 8: unsigned char case",
//                    a, b, 2,
//                    ft_strncmp(a, b, 2),
//                    strncmp(a, b, 2));
//     }

//     return 0;
// }