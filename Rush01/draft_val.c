#include <stdio.h>


int	count(int *arr, int size)
{
	int	count;
	int	i;
	int	temporary;

	i = 0;
	count = 1; 
	temporary = arr[0];
	while (i < size-1)
	{
		if (temporary < arr[i + 1])
		{
			count++;
			temporary = arr[i + 1];
		}
		printf("%d %d %d %d\n", arr[i], i, temporary, count);
		i++;
	}
	return (count);
}

int	main()
{
	int	arr1[4] = {2,1,3,4};

	printf("\n%d", count(arr1, 4));
}

int	solve(int grid[4][4], int pos, int row_left[4], int row_right[4], int col_up[4], int col_down[4])
{
	int row = pos / 4;
	int col = pos % 4;
	int val;

	if (pos == 16)
		return (1); // 全部填完，成功
	val = 1;
	while (val <= 4)
	{
		if (!is_in_row(grid, row, val) && !is_in_col(grid, col, val))
		{
			grid[row][col] = val;
			if (check_views(grid, row, col, row_left, row_right, col_up, col_down))
			{
				if (solve(grid, pos + 1, row_left, row_right, col_up, col_down))
					return (1);
			}
			grid[row][col] = 0; // 回溯
		}
		val++;
	}
	return (0);
