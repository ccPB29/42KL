/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 10:55:01 by luli2             #+#    #+#             */
/*   Updated: 2025-09-26 10:55:01 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr_base(int nb, char *base)
{
	long	i;
	int		l;

	if (value(base) == 0)
		return ;
	i = nb;
	l = len(base);
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}
	if (i < l)
	{
		write(1, &base[i], 1);
	}
	else
	{
		ft_putnbr_base(i / l, base);
		ft_putnbr_base(i % l, base);
	}
}

// int main(void)
// {
//     ft_putnbr_base(42, "01");          // 二进制: 101010
//     write(1, "\n", 1);
//     ft_putnbr_base(-42, "0123456789"); // 十进制: -42
//     write(1, "\n", 1);
//     ft_putnbr_base(255, "0123456789ABCDEF"); // 十六进制: FF
//     write(1, "\n", 1);
//     ft_putnbr_base(1234, "poneyvif");  // 八进制: 对应poneyvif字符
//     write(1, "\n", 1);
// }
