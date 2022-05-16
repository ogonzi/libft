/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:34:08 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 09:48:21 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Function: ft_bzero()
 * --------------------
 * Parameters:
 * 	s: Pointer to the start of memory location.
 * 	n: Number of bytes.
 * Return: None.
 * Description: The ft_bzero() function erases the data in the n bytes of the 
 * memory starting at the location pointed to by s, by writing zeros (bytes
 * containing '\0') to that area.
 */

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
