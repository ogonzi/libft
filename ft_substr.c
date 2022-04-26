/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:45:18 by ogonzale          #+#    #+#             */
/*   Updated: 2022/04/26 17:51:11 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	sub_s = (char *)malloc(len * sizeof(char));
	if (!sub_s)
		return (0);
	i = start;
	while (i < start + len)
	{
		sub_s[i - start] = s[i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
