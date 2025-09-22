/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fill.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: luli2 <marvin@42.fr>					   #+#  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025-09-21 10:00:00 by luli2			 #+#	#+#			 */
/*   Updated: 2025-09-21 10:00:00 by luli2			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

int		visible4(int v[4]);
int		check_top(int grid[4][4], int clues[16]);
int		check_bottom(int grid[4][4], int clues[16]);
int		check_left(int grid[4][4], int clues[16]);
int		check_right(int grid[4][4], int clues[16]);
int		check_grid(int grid[4][4], int clues[16]);

int		row_unique(int row[4]);
int		col_unique(int grid[4][4], int col);
int		unique(int grid[4][4], int row, int col);

int		validate_input(const char *str);
int		ft_atoi(const char *input_string, int *index_position);
void	init_grid(int grid[4][4]);

void	print(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
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

int	g_solved = 0;

int	check(int grid[4][4], int clues[16])
{
	if ((check_grid(grid, clues)))
	{
		print(grid);
		g_solved = 1;
	}
	return (1);
}

void	fill(int grid[4][4], int pos, int clues[16])
{
	int	row;
	int	col;
	int	val;

	row = pos / 4;
	col = pos % 4;
	if (g_solved)
		return ;
	if (pos == 16)
	{
		if (check(grid, clues))
			return ;
	}
	val = 1;
	while (val <= 4)
	{
		grid[row][col] = val;
		if (unique(grid, row, col))
		{
			fill(grid, pos + 1, clues);
		}
		grid[row][col] = 0;
		val++;
	}
}

int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int	clues[16];
	int	i;
	int	idp;

	if (argc != 2 || !validate_input(argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_grid(grid);
	i = 0;
	idp = 0;
	while (i < 16)
	{
		clues[i] = ft_atoi(argv[1], &idp);
		i++;
	}
	fill(grid, 0, clues);
	print(grid);
	if (g_solved == 0)
		write(1, "Error\n", 6);
}
