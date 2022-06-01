/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:00:41 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 12:22:19 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i] != '\0')
		ft_putchar_fd(s[i], fd);
	ft_putchar_fd('\n', fd);
}
