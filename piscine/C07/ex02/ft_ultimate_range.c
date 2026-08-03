/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 03:56:55 by luli2             #+#    #+#             */
/*   Updated: 2025-10-01 03:56:55 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof(int));
	if (!*range)
		return (-1);
	while (min < max)
		(*range)[i++] = min++;
	return (i);
}
