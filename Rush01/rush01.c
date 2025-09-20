int	cton(char c)
{
	int	i;

	i = c - '0';
	return (i);
}

int	count(int *arr)
{
	int	c;
	int	i;
	int	t;

	i = 0;
	c = 1;
	while (arr[i] && arr[i + 1])
	{
		if (arr[i] < arr[i + 1])
		{
			c++;
			t = arr[i + 1];
		}
		else
		{
			t = arr[i];
		}
		i++;
	}
}

void	main(int argc, char *argv[])
{

}