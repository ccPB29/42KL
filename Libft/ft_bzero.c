/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:05:05 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:44:15 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}

// #include <stdio.h>
// #include <string.h>     // 用于系统 memset / bzero 对比
// #include "libft.h"      // 你的 ft_bzero

// void print_bytes(unsigned char *p, size_t n)
// {
//     for (size_t i = 0; i < n; i++)
//         printf("%d ", p[i]);
//     printf("\n");
// }

// int main(void)
// {
//     printf("=== Test ft_bzero ===\n\n");

//     // Test 1: Basic zeroing
//     char buf1[10] = "XXXXXXXXX";
//     char buf2[10] = "XXXXXXXXX";

//     ft_bzero(buf1, 5);
//     memset(buf2, 0, 5);

//     printf("Test 1 (zero 5 bytes):\n");
//     printf("ft_bzero: "); print_bytes((unsigned char *)buf1, 10);
//     printf("memset  : "); print_bytes((unsigned char *)buf2, 10);
//     printf("Match? %s\n\n", memcmp(buf1, buf2, 10) == 0 ? "YES" : "NO");

//     // Test 2: n = 0 (should do nothing)
//     char t2_1[] = "abcdef";
//     char t2_2[] = "abcdef";

//     ft_bzero(t2_1, 0);
//     // no memset needed since n=0

//     printf("Test 2 (n = 0):\n");
//     printf("Unchanged? %s\n\n", strcmp(t2_1, t2_2) == 0 ? "YES" : "NO");

//     // Test 3: full clear
//     char buf3[8] = "ABCDEFG";
//     char buf4[8] = "ABCDEFG";

//     ft_bzero(buf3, 8);
//     memset(buf4, 0, 8);

//     printf("Test 3 (zero full array):\n");
//     printf("Match? %s\n\n", memcmp(buf3, buf4, 8) == 0 ? "YES" : "NO");

//     // Test 4: zeroing bytes inside a struct
//     struct { int a; char b[4]; } st1 = {1234, "YES"};
//     struct { int a; char b[4]; } st2 = {1234, "YES"};

//     ft_bzero(st1.b, 4);
//     memset(st2.b, 0, 4);

//     printf("Test 4 (zero struct field):\n");
//     printf("Match? %s\n\n", 
//memcmp(&st1, &st2, sizeof(st1)) == 0 ? "YES" : "NO");

//     return 0;
// }