/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:42:17 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:44:52 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
//     printf("=== Test ft_memset ===\n\n");

//     // Test 1: Basic fill
//     char buf1[20];
//     char buf2[20];

//     ft_memset(buf1, 'A', 10);
//     memset(buf2, 'A', 10);

//     printf("Test 1 (fill 'A', 10 bytes):\n");
//     printf("ft_memset: %.*s\n", 10, buf1);
//     printf("memset   : %.*s\n\n", 10, buf2);

//     // Test 2: Zero fill
//     ft_memset(buf1, 0, 5);
//     memset(buf2, 0, 5);

//     printf("Test 2 (fill 0, 5 bytes):\n");
//     printf("ft_memset: ");
//     for (int i = 0; i < 5; i++)
//         printf("%d ", (unsigned char)buf1[i]);
//     printf("\n");

//     printf("memset   : ");
//     for (int i = 0; i < 5; i++)
//         printf("%d ", (unsigned char)buf2[i]);
//     printf("\n\n");

//     // Test 3: Full block
//     char block1[50];
//     char block2[50];

//     ft_memset(block1, 'X', 50);
//     memset(block2, 'X', 50);

//     printf("Test 3 (full 50 bytes):\n");
//     printf("Result match? %s\n\n", 
//memcmp(block1, block2, 50) == 0 ? "YES" : "NO");

//     // Test 4: Test with n = 0 (should change nothing, return pointer)
//     char t4[] = "Hello";
//     char t4_sys[] = "Hello";

//     void *r1 = ft_memset(t4, 'Z', 0);
//     void *r2 = memset(t4_sys, 'Z', 0);

//     printf("Test 4 (n = 0):\n");
//     printf("Pointers match behavior: %s\n", (r1 == t4) ? "YES" : "NO");
//     printf("String unchanged: %s\n\n", 
//strcmp(t4, t4_sys) == 0 ? "YES" : "NO");

//     // Test 5: Non-char value
//     char t5_1[10];
//     char t5_2[10];

//     ft_memset(t5_1, 200, 10);
//     memset(t5_2, 200, 10);

//     printf("Test 5 (value = 200):\n");
//     printf("Result match? %s\n", memcmp(t5_1, t5_2, 10) == 0 ? "YES" : "NO");

//     return 0;
// }