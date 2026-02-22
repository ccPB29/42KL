/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:43:26 by luli2             #+#    #+#             */
/*   Updated: 2026/02/22 08:43:29 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_a_save(int fd, char *savestr)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(savestr, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(savestr);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		savestr = ft_strjoin(savestr, buff);
	}
	free(buff);
	return (savestr);
}

char	*extract_line(char *savestr)
{
	int		i;
	char	*str;

	i = 0;
	if (!savestr[i])
		return (NULL);
	while (savestr[i] && savestr[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (savestr[i] && savestr[i] != '\n')
	{
		str[i] = savestr[i];
		i++;
	}
	if (savestr[i] == '\n')
	{
		str[i] = savestr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_savestr(char *savestr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (savestr[i] && savestr[i] != '\n')
		i++;
	if (!savestr[i])
	{
		free(savestr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(savestr) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (savestr[i])
		str[j++] = savestr[i++];
	str[j] = '\0';
	free(savestr);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*savestr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	savestr = read_a_save(fd, savestr);
	if (!savestr)
		return (NULL);
	line = extract_line(savestr);
	savestr = new_savestr(savestr);
	return (line);
}

// # include <fcntl.h>
// # include <stdio.h>
// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }