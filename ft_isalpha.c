/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:53:27 by ogonzale          #+#    #+#             */
/*   Updated: 2022/04/25 11:08:18 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_isalpha()
 * ----------------------
 * PARAMETERS:
 *      c: Unsigned char to check
 * RETURN: The value returned is nonzero (1) if the char c falls into the
 * tested class, and zero if not.
 * DESCRIPTION: Checks fot an alphabetic character.
 */

int	ft_isalpha(int c)
{
	if (ft_islower(c) || ft_isupper(c))
		return (1);
	return (0);
}
