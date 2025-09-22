/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoong <gyoong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:18:57 by gyoong            #+#    #+#             */
/*   Updated: 2025/09/20 23:16:19 by gyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	visible4(int v[4]);

/* check_grid function checks if 4x4 grid matches 
the 16 visibility clues (eg col1top all the way to row4right)*/
int	check_top(int grid[4][4], int clues[16])
{
	int	arr[4];
	int	row;
	int	col;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			arr[row] = grid[row][col];
			row++;
		}
		if (visible4(arr) != clues[col])
			return (0);
		col++;
	}
	return (1);
}

int	check_bottom(int grid[4][4], int clues[16])
{
	int	arr[4];
	int	row;
	int	col;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			arr[row] = grid[3 - row][col];
			row++;
		}
		if (visible4(arr) != clues[4 + col])
			return (0);
		col++;
	}
	return (1);
}

int	check_left(int grid[4][4], int clues[16])
{
	int	arr[4];
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			arr[row] = grid[row][col];//col
			col++;
		}
		if (visible4(arr) != clues[8 + row])
			return (0);
		row++;
	}
	return (1);
}

int	check_right(int grid[4][4], int clues[16])
{
	int	arr[4];
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			arr[col] = grid[row][3 - col];
			col++;
		}
		if (visible4(arr) != clues[12 + row])
			return (0);
		row++;
	}
	return (1);
}

int	check_grid(int grid[4][4], int clues[16])
{
	if (!check_top(grid, clues))
		return (0);
	if (!check_bottom(grid, clues))
		return (0);
	if (!check_left(grid, clues))
		return (0);
	if (!check_right(grid, clues))
		return (0);
	return (1);
}
