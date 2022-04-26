/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:20:42 by ogonzale          #+#    #+#             */
/*   Updated: 2022/04/26 09:16:18 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*str_cpy;
	int		i;

	len = ft_strlen(str);
	str_cpy = (char *)malloc(len * sizeof(char) + 1);
	if (!str_cpy)
		return (0);
	i = -1;
	while (str[++i] != '\0')
		str_cpy[i] = str[i];
	str_cpy[i++] = '\0';
	return (str_cpy);
}
