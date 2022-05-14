/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:33:49 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/11 18:20:18 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_lst;
	t_list	*elem;

	if (!lst)
		return (0);
	f_lst = 0;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&f_lst, del);
			return (0);
		}
		ft_lstadd_back(&f_lst, elem);
		lst = lst->next;
	}
	return (f_lst);
}
