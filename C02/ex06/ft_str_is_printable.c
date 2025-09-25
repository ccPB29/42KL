/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 07:07:00 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 07:07:00 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s %s\n", "Hello123", ft_str_is_printable("Hello123"));
// 	printf("%s %s\n", "Hello World!", ft_str_is_printable("Hello World!"));
// 	printf("%s %s\n", "\nHello", ft_str_is_printable("\nHello"));
// 	printf("%s %s\n", "Tab\tTest", ft_str_is_printable("Tab\tTest"));
// 	printf("%s %s\n", "", ft_str_is_printable(""));

// 	return (0);
// }
