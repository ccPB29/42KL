/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:56:03 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:06:38 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>
// #include "libft.h"   // 你自己的头文件

// int main(void)
// {
//     printf("=== Test 1: Normal allocation ===\n");
//     int *a = ft_calloc(5, sizeof(int));
//     if (!a)
//         printf("FAILED: returned NULL\n");
//     else
//     {
//         printf("SUCCESS: allocated 5 ints\n");
//         for (int i = 0; i < 5; i++)
//             printf("a[%d] = %d\n", i, a[i]);   // 应全部打印 0
//         free(a);
//     }

//     printf("\n=== Test 2: nmemb = 0 ===\n");
//     char *b = ft_calloc(0, 10);
//     if (!b)
//         printf("FAILED: returned NULL\n");
//     else
//     {
//         printf("SUCCESS: returned non-NULL pointer for (0,10)\n");
//         free(b);
//     }

//     printf("\n=== Test 3: size = 0 ===\n");
//     char *c = ft_calloc(10, 0);
//     if (!c)
//         printf("FAILED: returned NULL\n");
//     else
//     {
//         printf("SUCCESS: returned non-NULL pointer for (10,0)\n");
//         free(c);
//     }

//     printf("\n=== Test 4: Overflow check ===\n");
//     size_t huge = SIZE_MAX / 2 + 1;
//     void *d = ft_calloc(huge, 3);  // 这个乘法一定溢出
//     if (!d)
//         printf("SUCCESS: overflow detected, returned NULL\n");
//     else
//     {
//         printf("FAILED: should have returned NULL on overflow\n");
//         free(d);
//     }

//     return 0;
// }