/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:47:30 by ogonzale          #+#    #+#             */
/*   Updated: 2022/04/26 10:11:58 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
