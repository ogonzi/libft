/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:25:57 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/10 09:47:06 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_one_empty_byte(void)
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (0);
	s[0] = '\0';
	return (s);
}

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
		return (ft_one_empty_byte());
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
	s[i - start] = '\0';
	return (s);
}
/*
int	main(void)
{
	char *s1 = "";
    char *ret = ft_strtrim(s1, "");

	printf("%s\n", ret);
	return (0);
}
*/
