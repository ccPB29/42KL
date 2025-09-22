/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visible4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoong <gyoong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:50:45 by gyoong            #+#    #+#             */
/*   Updated: 2025/09/20 22:56:04 by gyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* visible4 function counts how many boxes are 
visible from the left side of a row/column;
v[i] is the value of each array element (total 4);
max is the highest box have encountered so far;
count is the total number visible so far;
i is index of each array element;
*/
int	visible4(int v[4])
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (v[i] > max)
		{
			max = v[i];
			count++;
		}
		i++;
	}
	return (count);
}
