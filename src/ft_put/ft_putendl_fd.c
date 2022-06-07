/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:00:41 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/07 10:09:02 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_putend1_fd()
 * -------------------
 * PARAMETERS:
 *	s: The string to output.
 *	fd: The file descriptor on which to write.
 * RETURN: None.
 * DESCRIPTION: Outputs the string 's' to the given file descriptor followed
 * by a newline.
 */

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
