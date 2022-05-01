/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:12:43 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/01 10:06:40 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numsize(int n)
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
