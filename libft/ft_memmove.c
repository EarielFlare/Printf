/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:53:49 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/11 15:56:21 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*_src;
	char		*_dst;
	const char	*end_src;
	char		*end_dst;

	_src = (const char *)src;
	_dst = (char *)dst;
	if (_src || _dst)
	{
		if (_src < _dst)
		{
			end_dst = _dst + (len - 1);
			end_src = _src + (len - 1);
			while (len--)
				*end_dst-- = *end_src--;
		}
		if (_src > _dst)
		{
			while (len--)
				*_dst++ = *_src++;
		}
	}
	return ((void *)dst);
}
