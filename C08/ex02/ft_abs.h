/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 15:48:58 by luli2             #+#    #+#             */
/*   Updated: 2025-10-01 15:48:58 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) ((Value)*((-2)*(Value < 0)+1))

#endif

// #include <stdio.h>
// #include "ft_abs.h"

// int main(void)
// {
//     int a = -5;
//     int b = 0;
//     int c = 42;

//     printf("ABS(%d) = %d\n", a, ABS(a));
//     printf("ABS(%d) = %d\n", b, ABS(b));
//     printf("ABS(%d) = %d\n", c, ABS(c));
//     printf("ABS(%d) = %d\n", -100, ABS(-100));
//     printf("ABS(%d) = %d\n", 123, ABS(123));
//     return 0;
// }
