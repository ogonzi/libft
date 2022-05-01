/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:29:47 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/01 16:52:11 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_last(char const *s, char c, unsigned int i)
{
	while (s[i] == c)
	{
		i++;
		if (s[i] == '\0')
			return (1);
	}
	return (0);
}

static unsigned int	ft_get_num_splits(char const *s, char c)
{
	unsigned int	i;
	unsigned int	num_splits;

	i = 0;
	num_splits = 0;
	if (s[i] != c)
		num_splits++;
	while (s[i] != '\0')
	{
		if (s[i] == c && !ft_last(s, c, i))
			num_splits++;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (num_splits);
}

int	ft_allocate_and_split(char **str_split, char const *s, char c)
{
	int	i;
	int	j;
	int	start_split;

	j = 0;
	i = 0;
	while (s[i] != '\0' && !ft_last(s, c, i))
	{
		while (s[i] == c)
			i++;
		start_split = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		str_split[j] = (char *)malloc(sizeof(char) * (i - start_split + 1));
		if (!str_split[j])
			return (0);
		i = start_split - 1;
		while (s[++i] != c && s[i] != '\0')
			str_split[j][i - start_split] = s[i];
		str_split[j++][i - start_split] = '\0';
		if (s[i++] == '\0')
			break ;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	num_splits;
	char			**str_split;
	int				j;

	if (!s)
		return (0);
	num_splits = ft_get_num_splits(s, c);
	str_split = (char **)malloc(sizeof(char *) * (num_splits + 1));
	if (!str_split)
		return (0);
	if (num_splits == 0)
	{
		str_split[0] = NULL;
		return (str_split);
	}
	j = ft_allocate_and_split(str_split, s, c);
	if (!j)
		return (0);
	str_split[j] = NULL;
	return (str_split);
}
/*
int	main(void)
{
	char const *s = "casa de carlos no es cosa de carros";
	char		c = 'c';
	char		**split;
	int			i;

	split = ft_split(s, c);
	i = -1;
	while (split[++i] != NULL)
		printf("split: %s\n", split[i]);
	return (0);
}
*/
