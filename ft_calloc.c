/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:18:18 by ogonzale          #+#    #+#             */
/*   Updated: 2022/04/26 09:26:05 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*dst;
	size_t	total_size;

	total_size = size * number;
	dst = malloc(total_size);
	if (!dst)
		return (0);
	ft_memset(dst, 0, total_size);
	return (dst);
}
