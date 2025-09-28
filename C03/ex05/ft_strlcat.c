/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <marvin@42.fr>                       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 11:57:30 by luli2             #+#    #+#             */
/*   Updated: 2025-09-23 11:57:30 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (i >= (int)size)
		return ((int)size + j);
	c = 0;
	while (i + c <= (int)size - 1)
	{
		dest[i + c] = src[c];
		c++;
	}
	dest[i + c] = '\0';
	return (i + j);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char buf1[20] = "Hello";
// 	char buf2[20] = "Hello";
// 	unsigned int ret;

// 	// 情况1：size 足够大
// 	ret = ft_strlcat(buf1, " World", sizeof(buf1));
// 	printf("Case1: dest=\"%s\", return=%u\n", buf1, ret);

// 	// 情况2：size 太小（比 dest 还小）
// 	ret = ft_strlcat(buf2, " World", 3);
// 	printf("Case2: dest=\"%s\", return=%u\n", buf2, ret);

// 	// 情况3：size = 刚好等于 dest 长度 + 1
// 	char buf3[12] = "12345";
// 	ret = ft_strlcat(buf3, "6789", 6);
// 	printf("Case3: dest=\"%s\", return=%u\n", buf3, ret);

// 	//情况4：size 在 dest 长度和最终长度之间
// 	char buf4[4] = "ABC";
// 	ret = ft_strlcat(buf4, "DEFGHI", 6);
// 	printf("Case4: dest=\"%s\", return=%u\n", buf4, ret);

// 	return 0;
// }