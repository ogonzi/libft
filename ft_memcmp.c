/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:16:38 by ogonzale          #+#    #+#             */
/*   Updated: 2022/04/26 08:27:52 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				cmp;
	unsigned int	i;

	cmp = 0;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && ((unsigned char *)s1)[i] ==
			((unsigned char *)s2)[i])
		i++;
	cmp = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (cmp);
}
