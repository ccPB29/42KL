/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-01 11:41:57 by luli2             #+#    #+#             */
/*   Updated: 2025-11-01 11:41:57 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int atoi(const char *nptr)
{
	int result;
    int sign;

	result = 0;
	sign = 1;
    while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' ||
           *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
        nptr++;
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9') {
        result = result * 10 + (*nptr - '0');
        nptr++;
    }
    return (sign * result);
}