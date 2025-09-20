#include <unistd.h>
#include <stdio.h>


int	count(int *arr, int size)
{
	int	c;
	int	i;
	int	t;

	i = 0;
	c = 1; 
	t = arr[0];
	while (i < size-1)
	{
		if (t < arr[i + 1])
		{
			c++;
			t = arr[i + 1];
		}
		printf("%d %d %d %d\n", arr[i], i, t, c);
		i++;
	}
	return (c);
}



int	main()
{
	int	arr1[4] = {2,1,3,4};

	printf("\n%d", count(arr1, 4));
}