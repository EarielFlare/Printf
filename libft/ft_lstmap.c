/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 05:36:51 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/19 07:13:27 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_blank;

	if (!lst)
		return (NULL);
	new_list = (void *)0;
	while (lst)
	{
		new_blank = ft_lstnew(f(lst->content));
		if (!new_blank)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_blank);
		lst = lst->next;
	}
	return (new_list);
}
