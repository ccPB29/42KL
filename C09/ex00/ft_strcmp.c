/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-19 03:43:02 by luli2             #+#    #+#             */
/*   Updated: 2025-09-19 03:43:02 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s2[i] != s1[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	return ('\0' - s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     printf("%d %d\n", strcmp("ab", "abc"), ft_strcmp("ab", "abc")); 
//     printf("%d %d\n", strcmp("ab", "ab"), ft_strcmp("ab", "ab"));  
//     printf("%d %d\n", strcmp("abd", "ab"), ft_strcmp("abd", "ab"));  
// }