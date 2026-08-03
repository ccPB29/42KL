/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 16:39:13 by luli2             #+#    #+#             */
/*   Updated: 2025-10-01 16:39:13 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;	

#endif

// #include "ft_point.h"
// #include <stdio.h>
// void set_point(t_point *point)
// {
// point->x = 42;
// point->y = 21;
// }
// int main(void)
// {
// t_point point;
// set_point(&point);
// printf("%d %d ", point.x, point.y);
// return (0);
// }