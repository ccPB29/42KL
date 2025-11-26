/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:22:46 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 16:27:22 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>

// void    ft_putendl_fd(char *s, int fd);

// int main(void)
// {
//     int fd;

//     // 1. 输出到标准输出
//     ft_putendl_fd("Hello stdout", 1);

//     // 2. 输出到标准错误
//     ft_putendl_fd("Hello stderr", 2);

//     // 3. 输出到文件
//     fd = open("putendl_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd < 0)
//     {
//         perror("open failed");
//         return (1);
//     }
//     ft_putendl_fd("File test line 1", fd);
//     ft_putendl_fd("File test line 2", fd);
//     close(fd);

//     printf("Wrote to putendl_output.txt\n");
//     return (0);
// }