/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-13 12:14:04 by luli2             #+#    #+#             */
/*   Updated: 2025-09-13 12:14:04 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	t;
	int	i;

	while (size > 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				t = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = t;
			}
			i++;
		}
		size--;
	}
}

// #include <stdio.h>
// void print_array(int *tab, int size)
// {
//     for (int i = 0; i < size; i++)
//         printf("%d ", tab[i]);
//     printf("\n");
// }

// int main(void)
// {
//     int arr[] = {5, 2, 9, 1, 7};
//     int size = 5;

//     print_array(arr, size);
//     ft_sort_int_tab(arr, size);
//     print_array(arr, size);

//     return 0;
// }