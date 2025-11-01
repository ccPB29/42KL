/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-01 11:07:31 by luli2             #+#    #+#             */
/*   Updated: 2025-11-01 11:07:31 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *strrchr(const char *s, int c)
{
	char *last;

	last = NULL;
    while (*s) {
        if (*s == (char)c)
            last = (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return (last);
}