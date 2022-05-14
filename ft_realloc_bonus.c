/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:43:08 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/13 09:47:57 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*ptr_new;

	if (new_size == 0)
	{
		free(ptr);
		return (0);
	}
	else if (!ptr)
		return (malloc(new_size));
	else if (new_size <= original_size)
		return (ptr);
	else
	{
		ptr_new = malloc(new_size);
		if (ptr_new)
		{
			ptr_new = ft_memcpy(ptr_new, ptr, original_size);
			free(ptr);
		}
		return (ptr_new);
	}
}
