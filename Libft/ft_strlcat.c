/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-01 10:54:29 by luli2             #+#    #+#             */
/*   Updated: 2025-11-01 10:54:29 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t dlen;
	size_t i;

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