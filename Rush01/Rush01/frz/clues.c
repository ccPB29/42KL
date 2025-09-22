int	validate_input(const char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] < '1' || str[i] > '4')
			return (0);
		count++;
		i++;
		if (str[i] && str[i] != ' ')
			return (0);
	}
	if (count != 16)
		return (0);
	return (1);
}

int ft_atoi(const char *input_string, int *index_position)
{
    int number = 0;

    while (input_string[*index_position] == ' ')
    {
    (*index_position)++;
    }

    while (input_string[*index_position] >= '0' && input_string[*index_position] <= '9')
    {
        number = number * 10 + (input_string[*index_position] - '0');
        (*index_position)++;
    }

    return number;
}

#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return 1;
    }

    int clues[16];
    int i = 0;
    int idp = 0;

    while (i < 16)
    {
        clues[i] = ft_atoi(argv[1], &idp);
        i++;
    }

    for (i = 0; i < 16; i++)
        printf("%d", clues[i]);
    printf("\n");
	
    return 0;
}
