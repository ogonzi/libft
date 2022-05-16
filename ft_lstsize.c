/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:39:09 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 11:01:16 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_lstsize()
 * ----------------------
 * PARAMETERS:
 * 	lst:	The beggining of the list.
 * RETURN: The length of the list.
 * DESCRIPTION: Counts the number of nodes in a list.
 */

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
