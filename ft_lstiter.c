/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:31:16 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 10:48:47 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_lstiter()
 * ----------------------
 * PARAMETERS:
 * 	lst: The address of a pointer to a node.
 * 	f: The address of the function used to iterate on the list.
 * RETURN: None.
 * DESCRIPTION: Iterates the list 'lst' and applies the function 'f' on the 
 * content of each node.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
