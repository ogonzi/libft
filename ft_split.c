/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:29:47 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/01 11:45:28 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_not_last(char const *s, char c, unsigned int i)
{
	while (s[i] == c)
	{
		i++;
		if (s[i] == '\0')
			return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	num_splits;
	unsigned int	i;
	char			**str_split;

	if (!s)
		return (0);
	i = 0;
	num_splits = 0;
	if (s[i] != c)
		num_splits++;
	while (s[i] != '\0')
	{
		if (s[i] == c && ft_not_last(s, c))
			num_splits++;
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break;
		i++;
	}
	str_split = (char **)malloc(sizeof(char *) * (num_splits + 1));
	if (!str_split)
		return (0);
	
	return (str_split);
}
