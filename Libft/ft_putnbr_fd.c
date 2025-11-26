/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:24:51 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 16:30:23 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		nb = nb + '0';
		write(fd, &nb, 1);
	}
}

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <limits.h>

// void    ft_putnbr_fd(int n, int fd);

// int main(void)
// {
//     int fd;

//     // 1. 输出到标准输出
//     ft_putnbr_fd(42, 1);
//     write(1, "\n", 1);

//     ft_putnbr_fd(-12345, 1);
//     write(1, "\n", 1);

//     ft_putnbr_fd(0, 1);
//     write(1, "\n", 1);

//     ft_putnbr_fd(INT_MAX, 1);
//     write(1, "\n", 1);

//     ft_putnbr_fd(INT_MIN, 1);
//     write(1, "\n", 1);

//     // 2. 输出到标准错误
//     ft_putnbr_fd(999, 2);
//     write(2, "\n", 1);

//     // 3. 输出到文件
//     fd = open("putnbr_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd < 0)
//     {
//         perror("open failed");
//         return (1);
//     }

//     ft_putnbr_fd(123456, fd);
//     write(fd, "\n", 1);

//     ft_putnbr_fd(-987654, fd);
//     write(fd, "\n", 1);

//     close(fd);

//     printf("Wrote numbers to putnbr_output.txt\n");

//     return (0);
// }