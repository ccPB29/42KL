/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:43:10 by luli2             #+#    #+#             */
/*   Updated: 2026/02/22 08:43:13 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *savestr, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!savestr)
	{
		savestr = (char *)malloc(1 * sizeof(char));
		savestr[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(savestr) + ft_strlen(buff)) + 1));
	if (str == NULL)
	{
		free(savestr);
		return (NULL);
	}
	i = -1;
	j = 0;
	if (savestr)
		while (savestr[++i] != '\0')
			str[i] = savestr[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(savestr) + ft_strlen(buff)] = '\0';
	free(savestr);
	return (str);
}
