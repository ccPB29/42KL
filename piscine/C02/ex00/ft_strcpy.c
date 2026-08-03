/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-13 07:43:45 by luli2             #+#    #+#             */
/*   Updated: 2025-09-13 07:43:45 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dest[50];

// 	ft_strcpy(dest, src);
// 	printf("src:  \"%s\"\n", src);
// 	printf("dest: \"%s\"\n", dest);

// 	return (0);
// }