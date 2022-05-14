/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:46:00 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/14 16:01:20 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
/*
 * 1. Divide the number by the base to get the remainder 
 * (this will be the least (significant digit of the new
 * number in the other base).
 * 2. Then repeat the process by dividing the quotient of
 * step 1, by the new base. This time, the remainder is the
 * second digit.
 * 3. Repeat this process until the quotient becomes less
 * than the base. This quotient is the most significant digit.
 */

static int	ft_handle_edge_cases(char *base)
{	
	int	i;

	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
	}
	if (i < 2)
		return (0);
	return (1);
}

static void	ft_print(unsigned long int nbr, int i, char *base)
{
	int	j;
	int	num_arr[64];

	j = -1;
	while (++j < 64)
	{
		num_arr[j] = nbr % i;
		nbr = nbr / i;
	}
	j--;
	while (num_arr[j] == 0)
		j--;
	if (j == -2)
		j = 0;
	while (j >= 0)
	{
		if (num_arr[j] < 0)
			num_arr[j] = -num_arr[j];
		ft_putchar_fd(base[num_arr[j]], 1);
		j--;
	}
}

void	ft_putunbr_base(unsigned long int nbr, char *base)
{
	int	i;
	int	j;

	if (ft_handle_edge_cases(base) == 0)
		return ;
	i = -1;
	while (base[++i] != '\0')
	{
		j = i;
		while (base[++j] != '\0')
		{
			if (base[j] == base[i])
				return ;
		}
	}
	ft_print(nbr, i, base);
}
