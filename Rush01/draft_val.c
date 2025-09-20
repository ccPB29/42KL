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
