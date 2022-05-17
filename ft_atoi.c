/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:47:30 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/17 13:03:55 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_pow()
 * ------------------
 * PARAMETERS:
 * 	n:		Base number.
 *  pow:	Exponent.
 * RETURN: The value n raised to the power of y.
 * DESCRIPTION: A simplified version of pow(3). It is applied recursively with
 * the base case being that any number to the power of 0 is 1.
 */

static long double	ft_pow(long double n, unsigned int pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_pow(n, pow - 1));
}

/*
 * FUNCTION: ft_isspace()
 * ----------------------
 * PARAMETERS:
 * 	c:	Unsigned char to check
 * RETURN: The value returned is nonzero (1) if the char c falls into the
 * tested class, and zero if not.
 * DESCRIPTION: Checks for white-space characters. In the "C" and "POSIX"
 * locales, these are: space, form-feed ('\f'), newline ('\n'), carriage
 * return ('\r'), horizontal tab ('\t') and vertical tab ('\v')..
 */

static int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

/*
 * FUNCTION: ft_atoi()
 * -------------------
 * PARAMETERS:
 * 	nptr:	String to be converted.
 * RETURN: The converted value.
 * DESCRIPTION: The ft_atoi() function converts the initial portion of the
 * string pointed to be nptr to int. It trims prefix spaces and allows for one
 * sign (+ or -) before the number to be converted.
 */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	neg;
	int	start_num;

	i = 0;
	res = 0;
	neg = 0;
	while (ft_isspace(nptr[i]) && nptr[i] != '\0')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = 1;
		i++;
	}
	start_num = i - 1;
	while (ft_isdigit(nptr[i]) && nptr[i] != '\0')
		i++;
	while (++start_num < i)
		res = res + (nptr[start_num] - '0') * ft_pow(10, i - start_num - 1);
	if (neg == 1)
		res = -res;
	return (res);
}
