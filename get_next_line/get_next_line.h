/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:54 by luli2             #+#    #+#             */
/*   Updated: 2026/02/22 08:42:55 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_a_save(int fd, char *savestr);
char	*extract_line(char *savestr);
char	*new_savestr(char *savestr);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);

#endif