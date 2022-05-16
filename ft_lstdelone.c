/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:35:07 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 10:46:58 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_lstdelone()
 * ------------------------
 * PARAMETERS: 
 *	lst: The node to free.
 *	del: The address of the function used to delete the content.
 * RETURN: None.
 * DESCRIPTION: Takes as a parameter a node and frees the memory of the node's
 * content using the function 'del' given as a parameter and free the node. The
 * memory of 'next' must not be freed.
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
