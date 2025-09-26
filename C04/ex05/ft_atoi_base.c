/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 11:46:15 by luli2             #+#    #+#             */
/*   Updated: 2025-09-26 11:46:15 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	value(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (len(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	nbr(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	s;
	int	n;

	if (value(base) == 0)
		return (0);
	i = 0;
	s = 1;
	n = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (nbr(str[i], base) != -1)
	{
		n = n * len(base) + (nbr(str[i], base));
		i++;
	}
	return (n * s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi_base("   ---+--+12 34ab567", "0123456789"));
// 	// 结果：-1234 （因为符号里有 5 个 '-'，奇数次，取负）

// 	printf("%d\n", ft_atoi_base("   +101010", "01"));
// 	// 结果：42 （二进制 101010 = 42）

// 	printf("%d\n", ft_atoi_base("   -2A", "0123456789ABCDEF"));
// 	// 结果：-42 （16 进制 2A = 42）

// 	printf("%d\n", ft_atoi_base("  -ye", "poneyvif"));
// 	// “ye” = y(4)*8 + e(3) = 35，结果是 -35

// 	return (0);
// }
