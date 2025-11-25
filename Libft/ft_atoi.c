/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:41:57 by luli2             #+#    #+#             */
/*   Updated: 2025/11/25 14:29:26 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

// #include <stdio.h>
// #include <stdlib.h>   // 标准 atoi 用来对比
// #include "libft.h"    // 你的 ft_atoi

// static void test_case(const char *label, const char *input)
// {
//     int ft_r = ft_atoi(input);
//     int sys_r = atoi(input);

//     printf("%s\n", label);
//     printf("  input : \"%s\"\n", input);
//     printf("  ft_atoi : %d\n", ft_r);
//     printf("  atoi    : %d\n", sys_r);

//     printf("  Match? %s\n\n",
//            (ft_r == sys_r) ? "YES" : "NO");
// }

// int main(void)
// {
//     printf("=== Test ft_atoi ===\n\n");

//     // Test 1: simple number
//     test_case("Test 1: simple", "42");

//     // Test 2: + sign
//     test_case("Test 2: + sign", "+42");

//     // Test 3: - sign
//     test_case("Test 3: - sign", "-42");

//     // Test 4: leading whitespace
//     test_case("Test 4: whitespace", "   \t\n  123");

//     // Test 5: mixture whitespace + sign
//     test_case("Test 5: whitespace + sign", " \n  -56");

//     // Test 6: stops at non-digit
//     test_case("Test 6: stops at non-digit", "123abc456");

//     // Test 7: only sign (undefined, but ft must match atoi)
//     test_case("Test 7: only sign", "+");

//     // Test 8: empty string
//     test_case("Test 8: empty string", "");

//     // Test 9: leading zeros
//     test_case("Test 9: leading zeros", "0000123");

//     // Test 10: integer overflow positive
//     test_case("Test 10: overflow +", "99999999999999999999");

//     // Test 11: integer overflow negative
//     test_case("Test 11: overflow -", "-99999999999999999999");

//     // Test 12: mix invalid characters before digits
//     test_case("Test 12: invalid prefix", "++--++123");

//     // Test 13: space then invalid
//     test_case("Test 13: whitespace + invalid", "   +-5");

//     // Test 14: embedded NULL (just for safety)
//     {
//         char weird[] = {'1','2','3','\0','4','5'};
//         test_case("Test 14: embedded null", weird);
//     }

//     // Test 15: high ASCII (unsigned char issue)
//     {
//         char weird2[] = " \t\n\xFF" "123";
//         test_case("Test 15: weird high ascii", weird2);
//     }

//     return 0;
// }