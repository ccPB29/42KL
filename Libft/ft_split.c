/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:07:00 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 15:38:54 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	*extract_word(const char *s, char c)
{
	char	*word;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		num_words;
	int		i;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			split[i++] = extract_word(s, c);
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	split[num_words] = NULL;
	return (split);
	free_split(split);
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
// 	char **arr = ft_split("  hello 42  network   split ", ' ');
// 	int i = 0;

// 	while (arr[i])
// 	{
// 		printf("[%s]\n", arr[i]);
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return 0;
// }