/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:11:38 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:47:30 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (d == s)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
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
//     printf("=== Test ft_memmove ===\n\n");

//     // Test 1: Basic non-overlapping move
//     char src1[] = "Hello World!";
//     char dst1[20];
//     char dst2[20];

//     ft_memmove(dst1, src1, 12);
//     memmove(dst2, src1, 12);

//     printf("Test 1 (basic copy):\n");
//     printf("ft_memmove: %s\n", dst1);
//     printf("memmove   : %s\n\n", dst2);

//     // Test 2: Overlap - src before dest
//     char buf1[20] = "ABCDEFGHIJ";
//     char buf2[20] = "ABCDEFGHIJ";

//     ft_memmove(buf1 + 2, buf1, 8);
//     memmove(buf2 + 2, buf2, 8);

//     printf("Test 2 (overlap src < dest):\n");
//     printf("ft_memmove: %s\n", buf1);
//     printf("memmove   : %s\n", buf2);
//     printf("Match? %s\n\n", strcmp(buf1, buf2) == 0 ? "YES" : "NO");

//     // Test 3: Overlap - dest before src
//     char buf3[20] = "ABCDEFGHIJ";
//     char buf4[20] = "ABCDEFGHIJ";

//     ft_memmove(buf3, buf3 + 2, 8);
//     memmove(buf4, buf4 + 2, 8);

//     printf("Test 3 (overlap dest < src):\n");
//     printf("ft_memmove: %s\n", buf3);
//     printf("memmove   : %s\n", buf4);
//     printf("Match? %s\n\n", strcmp(buf3, buf4) == 0 ? "YES" : "NO");

//     // Test 4: n = 0
//     char t4_1[] = "abcdef";
//     char t4_2[] = "abcdef";

//     void *r1 = ft_memmove(t4_1, "ZZZZZZ", 0);
//     void *r2 = memmove(t4_2, "ZZZZZZ", 0);

//     printf("Test 4 (n = 0):\n");
//     printf("Unchanged? %s\n", strcmp(t4_1, t4_2) == 0 ? "YES" : "NO");
//     printf("Pointer returned correctly? %s\n\n", r1 == t4_1 ? "YES" : "NO");

//     // Test 5: Copy binary data
//     unsigned char raw1[10] = {1,2,3,4,5,6,7,8,9,10};
//     unsigned char raw2[10] = {1,2,3,4,5,6,7,8,9,10};
//     unsigned char raw3[10];
//     unsigned char raw4[10];

//     ft_memmove(raw3, raw1, 10);
//     memmove(raw4, raw2, 10);

//     printf("Test 5 (raw bytes):\n");
//     printf("Match? %s\n\n", memcmp(raw3, raw4, 10) == 0 ? "YES" : "NO");

//     printf("=== All tests finished ===\n");

//     return 0;
// }