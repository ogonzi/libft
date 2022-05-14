/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:14:49 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/14 11:03:35 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power_of_base(int i, char *base, char c)
{
	int	j;
	int	power_of_base;
	int	base_size;

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	power_of_base = 1;
	j = -1;
	while (++j < (i - 1))
		power_of_base = power_of_base * base_size;
	j = -1;
	while (base[++j] != 0)
	{
		if (c == base[j])
			power_of_base = power_of_base * j;
	}
	return (power_of_base);
}

static int	ft_handle_edge_cases(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[++j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
		}
	}
	if (i < 2)
		return (0);
	return (1);
}

static int	ft_is_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i] != '\0')
	{
		if (c == base[i])
			return (1);
	}
	return (0);
}

static int	ft_check_and_transform_num(char *str, char *base,
			int count_neg, int i)
{
	int	counter;
	int	res;

	counter = i - 1;
	res = 0;
	while ((ft_is_in_base(str[i], base) == 1) && str[i] != '\0')
		i++;
	while (++counter < i)
		res = res + ft_power_of_base(i - counter, base, str[counter]);
	if (count_neg % 2 == 1)
		res = -res;
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	count_neg;

	i = 0;
	res = 0;
	count_neg = 0;
	while ((str[i] >= '\t' && str[i] <= '\r' && str[i] != '\0')
		|| str[i] == ' ')
		i++;
	while ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
	{
		if (str[i] == '-')
			count_neg++;
		i++;
	}
	if (ft_handle_edge_cases(base) == 0)
		return (0);
	res = ft_check_and_transform_num(str, base, count_neg, i);
	return (res);
}
