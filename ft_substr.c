/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:45:18 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/10 08:31:31 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	size;

	if (len < ft_strlen(s))
		size = len + 1;
	else
		size = ft_strlen(s) + 1;
	sub_s = (char *)malloc(size * sizeof(char));
	if (!sub_s)
		return (0);
	if (start >= ft_strlen(s))
	{
		sub_s[0] = '\0';
		return (sub_s);
	}
	i = start;
	while (i < start + size - 1)
	{
		sub_s[i - start] = s[i];
		i++;
	}
	sub_s[i - start] = '\0';
	return (sub_s);
}
/*
int	main(void)
{
	char	*res;
	size_t	num;

	res = ft_substr("hola", 0, 0);
	printf("%s\n", res);
	return (0);
}
*/
