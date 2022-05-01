/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:25:57 by ogonzale          #+#    #+#             */
/*   Updated: 2022/04/26 19:00:09 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		len;
	int		start;
	int		end;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	while (ft_is_in_set(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (malloc(1));
	start = i;
	i = len - 1;
	while (ft_is_in_set(s1[i], set) && i >= 0)
		i--;
	end = i + 1;
	s = (char *)malloc((end - start + 1) * sizeof(char));
	if (!s)
		return (0);
	i = start - 1;
	while (++i < end)
		s[i - start] = s1[i];
	s[i] = '\0';
	return (s);
}
