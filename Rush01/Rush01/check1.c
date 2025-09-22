/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-21 10:34:47 by luli2             #+#    #+#             */
/*   Updated: 2025-09-21 10:34:47 by luli2            ###   ########.fr       */
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
			arr[col] = grid[row][col];
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

// #include <stdio.h>
// int main(void)
// {
//	 int grid[4][4] = {
//		 {2, 1, 4, 3},
//		 {3, 4, 1, 2},
//		 {4, 2, 3, 1},
//		 {1, 3, 2, 4}
//	 };

//	 // clues: top(0-3), bottom(4-7), left(8-11), right(12-15)
//	 int clues[16] = {2,2,1,3, 2,2,3,1, 3,2,2,1, 1,2,2,3};

//	 printf("check_top = %d\n", check_top(grid, clues));
//	 printf("check_bottom = %d\n", check_bottom(grid, clues));
//	 printf("check_left = %d\n", check_left(grid, clues));
//	 printf("check_right = %d\n", check_right(grid, clues));
//	 printf("check_grid = %d\n", check_grid(grid, clues));

//	 return 0;
// }
