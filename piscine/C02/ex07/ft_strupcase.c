/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 07:20:22 by luli2             #+#    #+#             */
/*   Updated: 2025-09-25 07:20:22 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str1[] = "Hello123world!";
// 	char str2[] = "alreadyUPPER";
// 	char str3[] = "mixED CaSe";
// 	char str4[] = "";

// 	printf("Before: %s\n", str1);
// 	printf("After : %s\n\n", ft_strupcase(str1));

// 	printf("Before: %s\n", str2);
// 	printf("After : %s\n\n", ft_strupcase(str2));

// 	printf("Before: %s\n", str3);
// 	printf("After : %s\n\n", ft_strupcase(str3));

// 	printf("Before: \"%s\"\n", str4);
// 	printf("After : \"%s\"\n", ft_strupcase(str4));

// 	return (0);
// }
