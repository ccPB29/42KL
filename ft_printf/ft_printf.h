/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:33:04 by luli2             #+#    #+#             */
/*   Updated: 2026/02/21 22:33:06 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_pointer(void *ptr);
int				ft_putchar(char c);
int				ft_puthex(unsigned long n, int uppercase);
int				ft_putnbr(int n);
int				ft_putstr(char *s);
int				ft_putusnbr(unsigned int m);

#endif
