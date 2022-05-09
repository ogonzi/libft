/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:45:18 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/09 18:02:36 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (0);
	if (start >= ft_strlen(s))
	{
		sub_s[0] = '\0';
		return (sub_s);
	}
	i = start;
	while (i < start + len)
	{
		sub_s[i - start] = s[i];
		i++;
	}
	sub_s[i - start] = '\0';
	return (sub_s);
}

int	main(void)
{
	char	*res;
	size_t	num;

	res = ft_substr("hola", 1, 1);
	printf("%s\n", res);
	return (0);
}

