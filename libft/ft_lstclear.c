/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 04:47:06 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/20 13:12:00 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (!*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		ptr = ptr->next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
	return ;
}
