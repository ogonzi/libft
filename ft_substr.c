/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:45:18 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 18:15:35 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(char const *s, unsigned int start, size_t len)
{
	if (start >= ft_strlen(s))
		return (1);
	if (start < ft_strlen(s) && (ft_strlen(s) - start) < len)
		return (ft_strlen(s) - start + 1);
	if (len < ft_strlen(s))
		return (len + 1);
	if (len >= ft_strlen(s))
		return (ft_strlen(s) + 1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	size;

	size = get_size(s, start, len);
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
