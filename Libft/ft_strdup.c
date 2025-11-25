/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:42:30 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:36:35 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len + 1);
	return (dup);
}

// #include <stdio.h>
// #include <string.h>
// #include "libft.h"    // 你的 ft_strdup、ft_strlen、ft_memcpy

// static void print_case(const char *label, 
//const char *src, char *ft_res, char *sys_res)
// {
//     printf("%s\n", label);
//     printf("  src      : \"%s\"\n", src);

//     if (ft_res)
//         printf("  ft_strdup : \"%s\"\n", ft_res);
//     else
//         printf("  ft_strdup : NULL\n");

//     if (sys_res)
//         printf("  strdup    : \"%s\"\n", sys_res);
//     else
//         printf("  strdup    : NULL\n");

//     int match = 0;
//     if (ft_res == NULL && sys_res == NULL)
//         match = 1;
//     else if (ft_res && sys_res && strcmp(ft_res, sys_res) == 0)
//         match = 1;

//     printf("  Match? %s\n\n", match ? "YES" : "NO");
// }

// int main(void)
// {
//     printf("=== Test ft_strdup ===\n\n");

//     // Test 1: normal string
//     {
//         const char *src = "Hello World!";
//         char *ft_res = ft_strdup(src);
//         char *sys_res = strdup(src);
//         print_case("Test 1: normal string", src, ft_res, sys_res);
//         free(ft_res);
//         free(sys_res);
//     }

//     // Test 2: empty string
//     {
//         const char *src = "";
//         char *ft_res = ft_strdup(src);
//         char *sys_res = strdup(src);
//         print_case("Test 2: empty string", src, ft_res, sys_res);
//         free(ft_res);
//         free(sys_res);
//     }

//     // Test 3: string with spaces
//     {
//         const char *src = "   42 KL   ";
//         char *ft_res = ft_strdup(src);
//         char *sys_res = strdup(src);
//         print_case("Test 3: spaces", src, ft_res, sys_res);
//         free(ft_res);
//         free(sys_res);
//     }

//     // Test 4: embedded null byte
//     {
//         char src[] = {'A','B','C','\0','D','E','F'};
//         char *ft_res = ft_strdup(src);
//         char *sys_res = strdup(src);
//         printf("Test 4: embedded null\n");
//         printf("  src raw bytes: A B C \\0 D E F\n");

//         // 打印字节更有意义
//         printf("  ft_strdup bytes: ");
//         for (size_t i = 0; i < 7; i++)
//             printf("%d ", (unsigned char)ft_res[i]);
//         printf("\n");

//         printf("  strdup bytes   : ");
//         for (size_t i = 0; i < 7; i++)
//             printf("%d ", (unsigned char)sys_res[i]);
//         printf("\n");

//         int match = memcmp(ft_res, sys_res, 7) == 0;
//         printf("  Match? %s\n\n", match ? "YES" : "NO");

//         free(ft_res);
//         free(sys_res);
//     }

//     // Test 5: long string
//     {
//         const char *src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
//         char *ft_res = ft_strdup(src);
//         char *sys_res = strdup(src);
//         print_case("Test 5: long string", src, ft_res, sys_res);
//         free(ft_res);
//         free(sys_res);
//     }

//     return 0;
// }