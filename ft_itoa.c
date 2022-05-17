/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:24:09 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/17 12:55:17 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_numsize()
 * ----------------------
 * PARAMETERS:
 *  n:  Int to check size
 * RETURN: The number of digits n has.
 * DESCRIPTION: The function ft_numsize() counts the number of digits a given
 * number has. The '-' is counted as a digit.
 */

static int	ft_numsize(int n)
{
	int	num_size;

	num_size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		num_size++;
	while (n != 0)
	{
		num_size++;
		n = n / 10;
	}
	return (num_size);
}

/*
 * FUNCTION: ft_pow()
 * ------------------
 * PARAMETERS:
 *  n:      Base number.
 *  pow:    Exponent.
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
 * FUNCTION: ft_abs_value()
 * ------------------------
 * PARAMETERS:
 *  n: The number on which to compute the absolute value.
 * RETURN: The absolute value.
 * DESCRIPTION: Computes the absolute value of a number.
 */

static size_t	ft_abs_value(long double n)
{
	if (n < 0)
		n = -n;
	return (n);
}

/*
 * FUNCTION: ft_itoa()
 * -------------------
 * PARAMETERS:
 * 	n: The integer to convert.
 * RETURN: The string representing the integer. NULL if the allocation fails.
 * DESCRIPTION: Allocates (with malloc(3)) and returns a string representing
 * the integer received as an argument. Negative numbers must be handled.
 */

char	*ft_itoa(int n)
{
	int		num_size;
	int		i;
	int		div;
	char	*num;

	num_size = ft_numsize(n);
	num = malloc(sizeof(char) * (num_size + 1));
	if (!num)
		return (0);
	i = 0;
	if (n < 0)
	{
		num[i] = '-';
		num_size--;
		i++;
	}
	div = ft_pow(10, num_size - 1);
	while (div >= 1)
	{
		num[i++] = ft_abs_value(n / div) + '0';
		n = n % div;
		div /= 10;
	}
	num[i] = '\0';
	return (num);
}
