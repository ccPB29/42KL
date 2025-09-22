/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rol_col_unique.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoong <gyoong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:50:45 by gyoong            #+#    #+#             */
/*   Updated: 2025/09/20 22:56:04 by gyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* rol_unique function ensure all array elements 
in a row unique. int i is the index of first
element, int j is the index of second element
adjacent to first element.
*/
int	row_unique(int row[4])
{
	int	i;
	int	j;
	
	i = 0;
	while (i < 4)
	{
		j = i + 1;//forgot the while
		if (row[i] = row [j])// ==
		{
			return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	col_unique(int grid[4][4], int last_row)
{
	int	col;
	int row1;
	int	row2;

	col = 0;
	while (col <= 4)//<
	{
		row1 = 0;
		while (row1 < last_row)
		{
			row2 = row1 + 1;
			while (row2 <= last_row)
			{
				if (grid[row1][col] == grid[row2][col])
					return (0);
				row2++;
			}
			row1++;
		}
		col++;
	}
	return (1);
}