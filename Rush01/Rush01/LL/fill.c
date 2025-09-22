#include <unistd.h>

int	visible4(int v[4]);
int	check_top(int grid[4][4], int clues[16]);
int	check_bottom(int grid[4][4], int clues[16]);
int	check_left(int grid[4][4], int clues[16]);
int	check_right(int grid[4][4], int clues[16]);
int	check_grid(int grid[4][4], int clues[16]);

int	row_unique(int row[4]);
int	col_unique(int grid[4][4], int col);
int unique(int grid[4][4], int row, int col);

void	print(int grid[4][4])
{
	int	i;
	int	j;
	char c;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			j++;
			if (j < 4)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

int	solved = 0;

void	fill(int grid[4][4], int pos, int clues[16])
{
	int	row;
	int	col;
	int	val;

	row = pos / 4;
	col = pos % 4;
	if (solved)
		return;
	if (pos == 16)
	{	
		if ((check_grid(grid, clues)))
		{
			print(grid);
			solved = 1;
		}
		return;
	}
	val = 1;
	while (val <= 4)
	{
		grid[row][col] = val;
		if (unique(grid, row, col))
		{
			fill(grid, pos+1, clues);
		}
		grid[row][col] = 0;
		val++;
	}
}

int	main(int argc, char *argv[])
{
	int	grid[4][4] = {0};
	int clues[16] = {4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2};

	fill(grid, 0, clues);
}