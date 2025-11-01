/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-01 11:13:03 by luli2             #+#    #+#             */
/*   Updated: 2025-11-01 11:13:03 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memchr(const void *s, int c, size_t n)
{
	const unsigned char *p;
    unsigned char uc;

    p = s;
	uc = c;
	while (n--) {
        if (*p == uc)
            return ((void *)p);
        p++;
    }
    return (NULL);
}