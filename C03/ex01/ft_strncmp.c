/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-19 10:40:36 by luli2             #+#    #+#             */
/*   Updated: 2025-09-19 10:40:36 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		if (s2[i] != s1[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	if (n == 0)
		return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     printf("%d %d\n", strcmp("ab", "abc"), ft_strcmp("ab", "abc")); 
//     printf("%d %d\n", strcmp("ab", "ab"), ft_strcmp("ab", "ab"));  
//     printf("%d %d\n", strcmp("abd", "ab"), ft_strcmp("abd", "ab"));  
// }