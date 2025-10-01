/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 03:48:55 by luli2             #+#    #+#             */
/*   Updated: 2025-10-01 03:48:55 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	i = 0;
	if (max <= min)
		return (NULL);
	arr = (int *)malloc((max - min) * sizeof(int));
	if (!arr)
		return (NULL);
	while (min < max)
		arr[i++] = min++;
	return (arr);
}
