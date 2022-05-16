/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:33:02 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 10:40:25 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_lstadd_front()
 * ---------------------------
 * PARAMETERS: 
 * 	lst: The address of a pointer to the first link of a list.
 * 	new: The address of a pointer to the node to be added to the list.
 * RETURN: None.
 * DESCRIPTION: Adds the node 'new' at the beginning of the list. If the list
 * is empty, lst is set to the new node. If the list is not empty. A node is
 * added to the beggining of the list by setting new->next to lst. Then lst
 * is set to new. Therefore a new node is linked to the beggining.
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}
