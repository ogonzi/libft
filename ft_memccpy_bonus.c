/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:27:38 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/10 09:39:53 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char buff1[] = "abcdefghijklmnopqrstuvwxyz";
	char buff2[] = "abcdefghijklmnopqrstuvwxyz";
	char *src = "string with\200inside !";

	__builtin___memccpy_chk
	(buff1, src, 0600, 21, __builtin_object_size (buff1, 0));
    ft_memccpy(buff2, src, 0600, 21);
    if (!ft_memcmp(buff1, buff2, 21))
        write(1, "success\n", 9);
    write(1, "failed\n", 8);
	printf("%s\n", buff1);
	printf("%s\n", buff2);
	return (0);
}
*/
