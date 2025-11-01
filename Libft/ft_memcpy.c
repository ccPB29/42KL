/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-01 10:06:08 by luli2             #+#    #+#             */
/*   Updated: 2025-11-01 10:06:08 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
    const unsigned char *s;

	d = dest;
	s = src;
    while (n--)
        *d++ = *s++;
    return (dest);
}