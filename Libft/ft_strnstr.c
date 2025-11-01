/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-01 11:34:57 by luli2             #+#    #+#             */
/*   Updated: 2025-11-01 11:34:57 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t remaining;

    if (*little == '\0')
        return ((char *)big);
    while (*big != '\0' && len > 0)
	{
        b = big;
        l = little;
        remaining = len;
        while (*l != '\0' && remaining > 0 && *b == *l)
		{
            b++;
            l++;
            remaining--;
        }
        if (*l == '\0')
            return ((char *)big);
        big++;
        len--;
    }
    return (NULL); 
}
