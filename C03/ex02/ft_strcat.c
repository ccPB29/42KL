/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 08:13:29 by luli2             #+#    #+#             */
/*   Updated: 2025-09-23 08:13:29 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>

// char    *ft_strcat(char *dest, char *src);

// int main(void)
// {
//     char buffer[50] = "Hello";
//     char *src = " World!";
//     char *result;#include <stdio.h>

// char    *ft_strcat(char *dest, char *src);

// int main(void)
// {
//     char buffer[50] = "Hello";
//     char *src = " World!";
//     char *result;

//     printf("Before strcat: \"%s\"\n", buffer);

//     result = ft_strcat(buffer, src);

//     printf("After strcat:  \"%s\"\n", buffer);
//     printf("Return value:  \"%s\"\n", result);

//     ft_strcat(buffer, " How are you?");
//     printf("After 2nd strcat: \"%s\"\n", buffer);

//     return 0;
// }

//     printf("Before strcat: \"%s\"\n", buffer);

//     result = ft_strcat(buffer, src);

//     printf("After strcat:  \"%s\"\n", buffer);
//     printf("Return value:  \"%s\"\n", result);

//     ft_strcat(buffer, " How are you?");
//     printf("After 2nd strcat: \"%s\"\n", buffer);

//     return 0;
// }