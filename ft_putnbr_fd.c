/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:03:40 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 12:23:46 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_putnbr_fd()
 * ------------------------
 * PARAMETERS:
 * 	n:	The integer to output.
 * 	fd:	The file descriptor on which to write.
 * RETURN: None.
 * DESCRIPTION: Outputs the integer 'n' to the given file descriptor.
 */

void	ft_putnbr_fd(int n, int fd)
{
	char	*num;

	num = ft_itoa(n);
	ft_putstr_fd(num, fd);
	free(num);
}

/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);	
}
*/
