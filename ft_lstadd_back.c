/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:46:19 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 10:36:36 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_lstadd_back()
 * --------------------------
 * PARAMETERS:
 * 	lst: The address of a pointer to the first link of a list.
 * 	new: The address of a pointer to the node to be added to the list.
 * RETURN: None.
 * DESCRIPTION: Adds the node 'new' at the end of the list. If new is NULL
 * the function returns. If the list is not empty, the last node of the list
 * is accessed (see ft_lstlast()) and the next node is set to 'new'. If the
 * list is empty, then the current node is set to 'new'.
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (new == NULL)
		return ;
	if (*lst != NULL)
	{
		node = ft_lstlast(*lst);
		node->next = new;
	}
	else
		*lst = new;
}
