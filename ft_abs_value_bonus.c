/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_value_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:37:33 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 09:38:03 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Function: ft_abs_value
 * ----------------------
 * Parameters:
 * 	n: The number on which to compute the absolute value.
 * Return: Absolute value.
 * Description: Computes the absolute value of a number.
 */

size_t	ft_abs_value(long double n)
{
	if (n < 0)
		n = -n;
	return (n);
}
