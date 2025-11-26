/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:17:55 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 16:27:26 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>

// void    ft_putchar_fd(char c, int fd);

// int main(void)
// {
//     int fd;

//     // 1. 输出到标准输出（Terminal）
//     ft_putchar_fd('A', 1);
//     ft_putchar_fd('\n', 1);

//     // 2. 输出到标准错误
//     ft_putchar_fd('E', 2);
//     ft_putchar_fd('\n', 2);

//     // 3. 输出到文件
//     fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd < 0)
//     {
//         perror("open failed");
//         return (1);
//     }
//     ft_putchar_fd('X', fd);
//     ft_putchar_fd('\n', fd);
//     close(fd);

//     printf("Wrote 'X' into output.txt\n");
//     return (0);
// }