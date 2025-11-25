/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:13:03 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:49:53 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		uc;

	p = s;
	uc = c;
	while (n--)
	{
		if (*p == uc)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// // 打印结果辅助函数
// static void print_res(const char *label, void *ft_res, void *sys_res)
// {
//     printf("%s\n", label);

//     if (ft_res)
//         printf("  ft_memchr : 
//found at offset %ld\n", (long)((unsigned char *)ft_res));
//     else
//         printf("  ft_memchr : NULL\n");

//     if (sys_res)
//         printf("  memchr    : 
//found at offset %ld\n", (long)((unsigned char *)sys_res));
//     else
//         printf("  memchr    : NULL\n");

//     // 判断是否一致（两者同为 NULL 或指向同样偏移）
//     if (ft_res == sys_res)
//         printf("  Match? YES\n\n");
//     else
//         printf("  Match? NO\n\n");
// }

// int main(void)
// {
//     printf("=== Test ft_memchr ===\n\n");

//     // Test 1: 正常找到字符
//     {
//         const char s[] = "Hello World!";
//         void *ft_r = ft_memchr(s, 'o', 12);
//         void *sys_r = memchr(s, 'o', 12);

//         printf("Test 1: find 'o'\n");
//         printf("  ft_memchr : %s\n", ft_r ? (char *)ft_r : "NULL");
//         printf("  memchr    : %s\n\n", sys_r ? (char *)sys_r : "NULL");
//     }

//     // Test 2: 未找到字符
//     {
//         const char s[] = "Hello World!";
//         void *ft_r = ft_memchr(s, 'x', 12);
//         void *sys_r = memchr(s, 'x', 12);

//         print_res("Test 2: find 'x' (not present)", ft_r, sys_r);
//     }

//     // Test 3: c == '\0'（必须能找到）
//     {
//         const char s[] = "ABCDEF";
//         void *ft_r = ft_memchr(s, '\0', 7);
//         void *sys_r = memchr(s, '\0', 7);

//         print_res("Test 3: find '\\0'", ft_r, sys_r);
//     }

//     // Test 4: 搜索长度小于字符串长度
//     {
//         const char s[] = "Hello World!";
//         void *ft_r = ft_memchr(s, 'o', 4);  // 4 个字节以内没有 'o'
//         void *sys_r = memchr(s, 'o', 4);

//         print_res("Test 4: limit shorter than index", ft_r, sys_r);
//     }

//     // Test 5: 二进制数据
//     {
//         unsigned char buf[] = {1, 2, 3, 4, 5, 3, 9};
//         void *ft_r = ft_memchr(buf, 3, 7);
//         void *sys_r = memchr(buf, 3, 7);

//         printf("Test 5: raw bytes\n");
//         printf("  ft offset : %ld\n", 
//ft_r ? (long)((unsigned char*)ft_r - buf) : -1);
//         printf("  sys offset: %ld\n\n", 
//sys_r ? (long)((unsigned char*)sys_r - buf) : -1);
//     }

//     // Test 6: unsigned char correctness
//     {
//         unsigned char buf[] = {0x01, 0x7F, 0x80, 0xFF};
//         void *ft_r = ft_memchr(buf, 0xFF, 4);
//         void *sys_r = memchr(buf, 0xFF, 4);

//         printf("Test 6: unsigned char 0xFF\n");
//         printf("  Match? %s\n\n", (ft_r == sys_r) ? "YES" : "NO");
//     }

//     // Test 7: n == 0
//     {
//         const char s[] = "Hello";
//         void *ft_r = ft_memchr(s, 'H', 0);
//         void *sys_r = memchr(s, 'H', 0);

//         print_res("Test 7: n = 0", ft_r, sys_r);
//     }

//     return 0;
// }