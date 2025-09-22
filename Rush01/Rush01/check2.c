/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-21 10:36:55 by luli2             #+#    #+#             */
/*   Updated: 2025-09-21 10:36:55 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* unique function ensures that the element at (row, col)
   in a 4x4 grid does not duplicate any non-zero elements 
   in its row or column.
   int row: the row index of the element to check
   int col: the column index of the element to check
   returns 1 if unique, 0 otherwise
*/
int	row_unique(int row[4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (row[i] != 0 && row[i] == row [j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	col_unique(int grid[4][4], int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (grid[i][col] != 0 && grid[i][col] == grid[j][col])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	unique(int grid[4][4], int row, int col)
{
	if (!row_unique(grid[row]))
		return (0);
	if (!col_unique(grid, col))
		return (0);
	return (1);
}

// int main(void)
// {
//	 int grid[4][4] = {
//		 {1, 2, 3, 4},
//		 {2, 0, 4, 0},
//		 {0, 4, 0, 2},
//		 {4, 0, 2, 1}
//	 };

//	 int row_test[4] = {1, 2, 3, 4};
//	 int row_dup[4]  = {1, 2, 2, 4};

//	 printf("row_unique(row_test) = %d\n", row_unique(row_test)); // 1
//	 printf("row_unique(row_dup) = %d\n", row_unique(row_dup));   // 0

//	 printf("col_unique(grid, 0) = %d\n", col_unique(grid, 0));   // 1
//	 printf("col_unique(grid, 1) = %d\n", col_unique(grid, 1));   // 1

//	 grid[1][0] = 1; 
//	 printf("unique(grid, 1, 0) = %d\n", unique(grid, 1, 0));	// 0

//	 grid[1][0] = 3;
//	 printf("unique(grid, 1, 0) = %d\n", unique(grid, 1, 0));	// 1

//	 return 0;
// }

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
