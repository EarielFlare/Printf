/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:58:17 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/19 07:12:52 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*res;

	if (lst && *lst && new)
	{
		res = ft_lstlast(*lst);
		res -> next = new;
	}
	if (lst && !*lst && new)
		*lst = new;
	return ;
}
