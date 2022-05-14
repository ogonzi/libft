/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:46:00 by ogonzale          #+#    #+#             */
/*   Updated: 2022/04/13 11:13:02 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_handle_edge_cases(char *base)
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

void	ft_print(int nbr, int i, int neg, char *base)
{
	int	j;
	int	num_arr[32];

	j = -1;
	while (++j < 32)
	{
		num_arr[j] = nbr % i;
		nbr = nbr / i;
	}
	j--;
	while (num_arr[j] == 0)
		j--;
	if (neg == 1)
		ft_putchar('-');
	if (j == -2)
		j = 0;
	while (j >= 0)
	{
		if (num_arr[j] < 0)
			num_arr[j] = -num_arr[j];
		ft_putchar(base[num_arr[j]]);
		j--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	j;
	int	neg;

	neg = 0;
	if (nbr < 0)
		neg = 1;
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
	ft_print(nbr, i, neg, base);
}