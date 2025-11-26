/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:21:49 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 16:27:11 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>

// void    ft_putstr_fd(char *s, int fd);

// int main(void)
// {
//     int fd;

//     // 1. 输出到标准输出（stdout）
//     ft_putstr_fd("Hello stdout\n", 1);

//     // 2. 输出到标准错误（stderr）
//     ft_putstr_fd("Hello stderr\n", 2);

//     // 3. 输出到文件
//     fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd < 0)
//     {
//         perror("open failed");
//         return (1);
//     }
//     ft_putstr_fd("File output test\n", fd);
//     close(fd);

//     printf("Wrote to output.txt\n");
//     return (0);
// }