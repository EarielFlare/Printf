/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:36:06 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/19 02:01:38 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p_elem;

	p_elem = (t_list *)malloc(sizeof(t_list));
	if (!p_elem)
		return (NULL);
	p_elem->content = content;
	p_elem->next = NULL;
	return (p_elem);
}
