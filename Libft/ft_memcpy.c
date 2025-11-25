/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:06:08 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:47:07 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// void print_bytes(unsigned char *p, size_t n)
// {
//     for (size_t i = 0; i < n; i++)
//         printf("%d ", p[i]);
//     printf("\n");
// }

// int main(void)
// {
//     printf("=== Test ft_memcpy ===\n\n");
//     // Test 1: Basic copy
//     char src1[20] = "Hello World!";
//     char dst1[20] = "XXXXXXXXXXXX";
//     char dst2[20] = "XXXXXXXXXXXX";
//     ft_memcpy(dst1, src1, 12);
//     memcpy(dst2, src1, 12);

//     printf("Test 1 (basic copy):\n");
//     printf("ft_memcpy: %s\n", dst1);
//     printf("memcpy   : %s\n\n", dst2);
//     // Test 2: Copy bytes including '\0'
//     char src2[] = "ABC\0DEF";
//     char dst3[10] = "ZZZZZZZZZ";
//     char dst4[10] = "ZZZZZZZZZ";
//     ft_memcpy(dst3, src2, 7);
//     memcpy(dst4, src2, 7);

//     printf("Test 2 (copy with embedded null):\n");
//     printf("Match? %s\n\n", memcmp(dst3, dst4, 7) == 0 ? "YES" : "NO");
//     // Test 3: n = 0 (should return dest, no changes)
//     char t3_1[] = "abcdef";
//     char t3_2[] = "abcdef";
//     void *ret1 = ft_memcpy(t3_1, "ZZZZZZ", 0);
//     void *ret2 = memcpy(t3_2, "ZZZZZZ", 0);

//     printf("Test 3 (n = 0):\n");
//     printf("Unchanged? %s\n", strcmp(t3_1, t3_2) == 0 ? "YES" : "NO");
//     printf("Pointer returned correctly? %s\n\n", 
//		ret1 == t3_1 ? "YES" : "NO");

//     // Test 4: Copy raw bytes (non-char)
//     unsigned char src4[5] = {1, 2, 3, 4, 5};
//     unsigned char dst5[5];
//     unsigned char dst6[5];

//     ft_memcpy(dst5, src4, 5);
//     memcpy(dst6, src4, 5);

//     printf("Test 4 (raw bytes):\n");
//     printf("Match? %s\n\n", memcmp(dst5, dst6, 5) == 0 ? "YES" : "NO");

//     // Test 5: Overlap case (should NOT behave like memmove)
//     char src5[20] = "ABCDEFGHIJ";
//     ft_memcpy(src5 + 2, src5, 10); 
// //Undefined behavior, but we test crash or odd behavior

//     printf("Test 5 (overlap, undefined behavior in memcpy):\n");
//     printf("NOTE: memcpy is NOT safe for overlap, so results may differ.\n");
//     printf("Result: %s\n", src5);
//     printf("If your ft_memcpy == memmove → WRONG implementation.\n\n");

//     printf("=== All tests finished ===\n");

//     return 0;
// }