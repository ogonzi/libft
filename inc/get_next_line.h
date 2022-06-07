/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:27:41 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/07 10:11:47 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* get_next_line.c */
char			*get_next_line(int fd);

/* get_next_line_utils.c */
char			*ft_substr(char **s, unsigned int start, unsigned int len);
unsigned int	ft_strlen(const char *s);
void			ft_strcpy(char **dest, char **src, unsigned int n);
void			ft_strset(char **s, int c, unsigned int n);
#endif
