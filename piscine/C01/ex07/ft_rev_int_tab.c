/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-13 10:18:55 by luli2             #+#    #+#             */
/*   Updated: 2025-09-13 10:18:55 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	t;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		t = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = t;
		i++;
	}
}

// #include <stdio.h>
// int	main(void)
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     int size = 5;

//     ft_rev_int_tab(arr, size);

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }