/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:45:00 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:48:12 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i + 1 < size && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
//     printf("=== Test ft_strlcpy ===\n\n");

//     // Test 1: Basic copy
//     char dst1[20];
//     char dst2[20];
//     size_t r1 = ft_strlcpy(dst1, "Hello", 20);
//     size_t r2 = strlcpy(dst2, "Hello", 20);

//     printf("Test 1 (basic copy):\n");
//     printf("dst1: %s | ret = %zu\n", dst1, r1);
//     printf("dst2: %s | ret = %zu\n\n", dst2, r2);

//     // Test 2: size = 0
//     char d3[10] = "XXXXXXXXX";
//     char d4[10] = "XXXXXXXXX";
//     size_t r3 = ft_strlcpy(d3, "ABCDE", 0);
//     size_t r4 = strlcpy(d4, "ABCDE", 0);

//     printf("Test 2 (size = 0):\n");
//     printf("dst unchanged? %s\n", strcmp(d3, d4) == 0 ? "YES" : "NO");
//     printf("ret matches? %s (ft=%zu, sys=%zu)\n\n",
//            (r3 == r4) ? "YES" : "NO", r3, r4);

//     // Test 3: Small buffer
//     char d5[5];
//     char d6[5];
//     size_t r5 = ft_strlcpy(d5, "ABCDEFG", 5);
//     size_t r6 = strlcpy(d6, "ABCDEFG", 5);

//     printf("Test 3 (size = 5):\n");
//     printf("dst1: %s | ret = %zu\n", d5, r5);
//     printf("dst2: %s | ret = %zu\n", d6, r6);
//     printf("Match? %s\n\n", 
//(strcmp(d5, d6) == 0 && r5 == r6) ? "YES" : "NO");

//     // Test 4: Exact buffer size
//     char d7[6];
//     char d8[6];
//     size_t r7 = ft_strlcpy(d7, "ABCDE", 6);
//     size_t r8 = strlcpy(d8, "ABCDE", 6);

//     printf("Test 4 (size exactly len+1):\n");
//     printf("Match? %s\n\n", 
//(strcmp(d7, d8) == 0 && r7 == r8) ? "YES" : "NO");

//     // Test 5: Copy empty string
//     char d9[10];
//     char d10[10];
//     size_t r9 = ft_strlcpy(d9, "", 10);
//     size_t r10 = strlcpy(d10, "", 10);

//     printf("Test 5 (empty string):\n");
//     printf("Match? %s\n\n", 
//(strcmp(d9, d10) == 0 && r9 == r10) ? "YES" : "NO");

//     // Test 6: Source contains embedded '\0'
//     char src6[] = {'A','B','C','\0','D','E','F'};
//     char d11[10] = "ZZZZZZZZ";
//     char d12[10] = "ZZZZZZZZ";

//     size_t r11 = ft_strlcpy(d11, src6, 10);
//     size_t r12 = strlcpy(d12, src6, 10);

//     printf("Test 6 (embedded null):\n");
//     printf("Match? %s\n\n", 
//(memcmp(d11, d12, 10) == 0 && r11 == r12) ? "YES" : "NO");

//     return 0;
// }