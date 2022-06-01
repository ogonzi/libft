/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:24:02 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/01 18:46:21 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

/*
 * FUNCTION: ft_get_size()
 * -----------------------
 * PARAMETERS:
 * s:		The string from which to create the substring.
 * start:	The start index of the substring in the string 's'.
 * len:		The maximum length of the substring.
 * RETURN: The necessary allocation space.
 * DESCRIPTION: The function ft_get_size() takes into account the different
 * possible combinations between the three parameters and returns the 
 * corresponding size for each case.
 */

static unsigned int	ft_get_size(unsigned int start,
			unsigned int len, unsigned int len_s)
{
	if (start >= len_s)
		return (1);
	if (start < len_s && (len_s - start) < len)
		return (len_s - start + 1);
	if (len < len_s)
		return (len + 1);
	if (len >= len_s)
		return (len_s + 1);
	return (0);
}

/*
 * FUNCTION: ft_substr()
 * ---------------------
 * PARAMETERS:
 * 	s:		The string from which to create the substring.
 * 	start:	The start index of the substring in the string 's'.
 * 	len:	The maximum length of the substring.
 * RETURN: The substring. NULL if the allocation fails.
 * DESCRIPTION: Allocates (with malloc(3)) and returns a substring from
 * the string 's'. The substring begins at index 'start' and is of maximum 
 * size 'len'.
 * DEV: Since there are 3 variables that can determine the size of
 * necessary memory a function (ft_get_size) is used to determine the size.
 */

char	*ft_substr(char **s, unsigned int start, unsigned int len)
{
	char			*sub_s;
	unsigned int	i;
	unsigned int	size;
	unsigned int	len_s;

	len_s = ft_strlen(*s);
	size = ft_get_size(start, len, len_s);
	sub_s = malloc(size * sizeof(char));
	if (!sub_s)
	{
		free(*s);
		return (0);
	}
	i = start;
	while (i < start + size - 1)
	{
		sub_s[i - start] = (*s)[i];
		i++;
	}
	sub_s[i - start] = '\0';
	return (sub_s);
}

unsigned int	ft_strlen(const char *s)
{
	unsigned int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_strcpy(char **dest, char **src, unsigned int n)
{
	unsigned int	i;

	if (!(*dest) && !(*src))
		return ;
	i = 0;
	while (i < n)
	{
		(*dest)[i] = (*src)[i];
		i++;
	}
}

void	ft_strset(char **s, int c, unsigned int n)
{
	unsigned int	i;

	if (!(*s))
		return ;
	i = 0;
	while (i < n)
	{
		(*s)[i] = c;
		i++;
	}
}
