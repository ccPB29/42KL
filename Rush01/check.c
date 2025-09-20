int check_row(int grid[4][4], int row, int row_left[4], int row_right[4])
{
	int line[4];
	int col;

	for (col = 0; col < 4; col++)
		line[col] = grid[row][col];
	// If row not full, skip check
	for (col = 0; col < 4; col++)
		if (line[col] == 0)
			return 1;
	// Check left view
	if (count_visible(line, 4) != row_left[row])
		return 0;
	// Check right view (reversed)
	if (count_visible((int[]){line[3], line[2], line[1], line[0]}, 4) != row_right[row])
		return 0;
	return 1;
}

int check_col(int grid[4][4], int col, int col_up[4], int col_down[4])
{
	int line[4];
	int row;

	for (row = 0; row < 4; row++)
		line[row] = grid[row][col];
	// If column not full, skip check
	for (row = 0; row < 4; row++)
		if (line[row] == 0)
			return 1;
	if (count_visible(line, 4) != col_up[col])
		return 0;
	if (count_visible((int[]){line[3], line[2], line[1], line[0]}, 4) != col_down[col])
		return 0;
	return 1;
}

int check_views(int grid[4][4], int row, int col,
	int row_left[4], int row_right[4],
	int col_up[4], int col_down[4])
{
	if (!check_row(grid, row, row_left, row_right))
		return 0;
	if (!check_col(grid, col, col_up, col_down))
		return 0;
	return 1;
}
