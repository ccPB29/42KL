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
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     printf("%d %d\n", strncmp("", "abc", 2), ft_strncmp("", "abc", 2)); 
//     printf("%d %d\n", strncmp("ab", "ab", 4), ft_strncmp("ab", "ab", 4));  
//     printf("%d %d\n", strncmp("abd", "ab",4), ft_strncmp("abd", "ab", 4));  
// }