/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:54:29 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:11:32 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;

	dlen = 0;
	i = 0;
	while (dlen < size && dst[dlen] != '\0')
		dlen++;
	if (dlen == size)
		return (size);
	while (dlen + i + 1 < size && src[i] != '\0')
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	while (src[i] != '\0')
		i++;
	return (dlen + i);
}

// #include <stdio.h>
// #include <string.h>
// // 在很多 Linux/glibc 系统上需要这个头文件和 -lbsd：
// // #include <bsd/string.h>

// #include "libft.h"

// static void print_case(const char *label,
//                        const char *dst, const char *src,
//                        size_t size, size_t r_ft, size_t r_sys,
//                        const char *dst_ft, const char *dst_sys)
// {
//     printf("%s\n", label);
//     printf("  dst init : \"%s\"\n", dst);
//     printf("  src      : \"%s\"\n", src);
//     printf("  size     : %zu\n", size);
//     printf("  ft_strlcat dst : \"%s\", ret = %zu\n", dst_ft, r_ft);
//     printf("  strlcat   dst : \"%s\", ret = %zu\n", dst_sys, r_sys);
//     printf("  Match? %s\n\n",
//            (r_ft == r_sys && strcmp(dst_ft, dst_sys) == 0) ? "YES" : "NO");
// }

// int main(void)
// {
//     printf("=== Test ft_strlcat ===\n\n");

//     // Test 1: size 足够大，完全拼接
//     {
//         char dst1_ft[30]  = "Hello";
//         char dst1_sys[30] = "Hello";
//         const char *src = " World";
//         size_t size = sizeof(dst1_ft);

//         size_t r1 = ft_strlcat(dst1_ft, src, size);
//         size_t r2 = strlcat(dst1_sys, src, size);

//         print_case("Test 1: size >= dst_len + src_len + 1",
//                    "Hello", src, size, r1, r2, dst1_ft, dst1_sys);
//     }

//     // Test 2: size 较小，只能拼接一部分
//     {
//         char dst2_ft[10]  = "Hello";
//         char dst2_sys[10] = "Hello";
//         const char *src = "World";
//         size_t size = 8;  // "HelloWo" + '\0'

//         size_t r1 = ft_strlcat(dst2_ft, src, size);
//         size_t r2 = strlcat(dst2_sys, src, size);

//         print_case("Test 2: size 介于 dst_len+1 和 dst_len+src_len 之间（部分拼接）",
//                    "Hello", src, size, r1, r2, dst2_ft, dst2_sys);
//     }

//     // Test 3: size <= dst_len，应该不拼接，返回 size + src_len
//     {
//         char dst3_ft[10]  = "Hello";
//         char dst3_sys[10] = "Hello";
//         const char *src = "World";
//         size_t size = 3;  // 小于 dst_len

//         size_t r1 = ft_strlcat(dst3_ft, src, size);
//         size_t r2 = strlcat(dst3_sys, src, size);

//         print_case("Test 3: size <= dst_len（不应拼接）",
//                    "Hello", src, size, r1, r2, dst3_ft, dst3_sys);
//     }

//     // Test 4: size = 0，不应该写入，但要返回 dst_len + src_len
//     {
//         char dst4_ft[10]  = "Hello";
//         char dst4_sys[10] = "Hello";
//         const char *src = "World";
//         size_t size = 0;

//         size_t r1 = ft_strlcat(dst4_ft, src, size);
//         size_t r2 = strlcat(dst4_sys, src, size);

//         print_case("Test 4: size = 0（不写 dst，返回 dst_len + src_len）",
//                    "Hello", src, size, r1, r2, dst4_ft, dst4_sys);
//     }

//     // Test 5: src 为空字符串
//     {
//         char dst5_ft[10]  = "Hello";
//         char dst5_sys[10] = "Hello";
//         const char *src = "";
//         size_t size = sizeof(dst5_ft);

//         size_t r1 = ft_strlcat(dst5_ft, src, size);
//         size_t r2 = strlcat(dst5_sys, src, size);

//         print_case("Test 5: src 为空字符串",
//                    "Hello", src, size, r1, r2, dst5_ft, dst5_sys);
//     }

//     // Test 6: dst 初始为空串
//     {
//         char dst6_ft[10]  = "";
//         char dst6_sys[10] = "";
//         const char *src = "World";
//         size_t size = sizeof(dst6_ft);

//         size_t r1 = ft_strlcat(dst6_ft, src, size);
//         size_t r2 = strlcat(dst6_sys, src, size);

//         print_case("Test 6: dst 初始为空串",
//                    "", src, size, r1, r2, dst6_ft, dst6_sys);
//     }

//     return 0;
// }