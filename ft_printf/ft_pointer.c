/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:31:22 by luli2             #+#    #+#             */
/*   Updated: 2026/02/21 22:31:28 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *ptr)
{
	int	count;

	if (ptr == NULL)
	{
		return (ft_putstr("(nil)"));
	}
	count = 0;
	count += write(1, "0x", 2);
	count += ft_puthex((unsigned long)ptr, 0);
	return (count);
}
