/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:08:12 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/01 11:22:03 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*f_s;
	unsigned int		i;

	if (!s || !f)
		return (0);
	f_s = ft_strdup(s);
	if (!f_s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		f_s[i] = f(i, f_s[i]);
		i++;
	}
	return (f_s);
}
